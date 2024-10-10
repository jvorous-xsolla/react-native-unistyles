import type { UnistylesTheme } from '../types'
import type { UnistylesConfig } from '../specs/StyleSheet'
import type { AppBreakpoint, AppThemeName } from '../specs/types'
import type { UnistylesBreakpoints, UnistylesThemes } from '../global'
import { UnistylesRuntime } from './runtime'
import { isServer, schemeToTheme } from './utils'
import { UnistylesListener } from './listener'
import { UnistyleDependency } from '../specs/NativePlatform'

class UnistylesStateBuilder {
    private readonly isSSR = isServer()

    themes = new Map<string, UnistylesTheme>()
    themeName?: AppThemeName

    breakpoint?: AppBreakpoint
    breakpoints?: UnistylesBreakpoints

    hasAdaptiveThemes = false

    init = (config: UnistylesConfig) => {
        this.initThemes(config.themes)
        this.initBreakpoints(config.breakpoints)
        this.initSettings(config.settings)

        if (this.isSSR) {
            return
        }

        UnistylesListener.initListeners()
    }

    private initThemes = (themes = {} as UnistylesThemes) => {
        Object.entries(themes).forEach(([themeName, theme]) => {
            this.themes.set(themeName, theme)
        })
    }

    private initSettings = (settings: UnistylesConfig['settings']) => {
        this.hasAdaptiveThemes = settings?.adaptiveThemes ?? false
        const themeNames = Array.from(this.themes.keys()) as Array<AppThemeName>

        // Single theme + no settings
        if (!settings?.adaptiveThemes && !settings?.initialTheme && themeNames.length === 1) {
            this.themeName = themeNames[0]

            return
        }

        // No settings
        if (!settings?.adaptiveThemes && !settings?.initialTheme) {
            throw new Error('🦄 You need to specify either "initialTheme" or "adaptiveThemes" in your config')
        }

        // Adaptive themes
        if (settings.adaptiveThemes) {
            this.themeName = schemeToTheme(UnistylesRuntime.colorScheme)

            return
        }

        // Initial theme
        this.themeName = typeof settings.initialTheme === 'function' ? settings.initialTheme() : settings.initialTheme
    }

    private initBreakpoints = (breakpoints = {} as UnistylesBreakpoints) => {
        const breakpointsMap = new Map<string, MediaQueryList>()

        this.breakpoints = breakpoints

        Object.entries(breakpoints)
            .sort(([, a], [, b]) => a - b)
            .forEach(([breakpoint, value]) => {
                if (isServer()) {
                    return
                }

                const mediaQuery = window.matchMedia(`(min-width: ${value}px)`)
                breakpointsMap.set(breakpoint, mediaQuery)

                if (mediaQuery.matches) {
                    this.breakpoint = breakpoint as AppBreakpoint
                }

                mediaQuery.addEventListener('change', event => {
                    if (!event.matches) {
                        const [currentBreakpoint] = Array.from(breakpointsMap).find(([,mq]) => mq.matches) ?? []

                        if (currentBreakpoint) {
                            this.breakpoint = currentBreakpoint as AppBreakpoint
                            UnistylesListener.emitChange(UnistyleDependency.Breakpoints)
                        }

                        return
                    }

                    this.breakpoint = breakpoint as AppBreakpoint
                    UnistylesListener.emitChange(UnistyleDependency.Breakpoints)
                })
            })
    }
}

export const UnistylesState = new UnistylesStateBuilder()
