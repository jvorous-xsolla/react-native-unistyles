///
/// UnistylesCxxMiniRuntime.hpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#pragma once

#if __has_include(<NitroModules/JSIConverter.hpp>)
#include <NitroModules/JSIConverter.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif
#if __has_include(<NitroModules/NitroDefines.hpp>)
#include <NitroModules/NitroDefines.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif

// Forward declaration of `ColorScheme` to properly resolve imports.
namespace margelo::nitro::unistyles { enum class ColorScheme; }
// Forward declaration of `Dimensions` to properly resolve imports.
namespace margelo::nitro::unistyles { struct Dimensions; }
// Forward declaration of `Insets` to properly resolve imports.
namespace margelo::nitro::unistyles { struct Insets; }

#include <optional>
#include <string>
#include "ColorScheme.hpp"
#include "Dimensions.hpp"
#include "Insets.hpp"

namespace margelo::nitro::unistyles {

  /**
   * A struct which can be represented as a JavaScript object (UnistylesCxxMiniRuntime).
   */
  struct UnistylesCxxMiniRuntime {
  public:
    std::optional<std::string> themeName     SWIFT_PRIVATE;
    std::optional<std::string> breakpoint     SWIFT_PRIVATE;
    bool hasAdaptiveThemes     SWIFT_PRIVATE;
    ColorScheme colorScheme     SWIFT_PRIVATE;
    Dimensions screen     SWIFT_PRIVATE;
    std::string contentSizeCategory     SWIFT_PRIVATE;
    Insets insets     SWIFT_PRIVATE;
    double pixelRatio     SWIFT_PRIVATE;
    double fontScale     SWIFT_PRIVATE;
    bool rtl     SWIFT_PRIVATE;
    Dimensions statusBar     SWIFT_PRIVATE;
    Dimensions navigationBar     SWIFT_PRIVATE;
    bool isPortrait     SWIFT_PRIVATE;
    bool isLandscape     SWIFT_PRIVATE;

  public:
    UnistylesCxxMiniRuntime() = default;
    explicit UnistylesCxxMiniRuntime(std::optional<std::string> themeName, std::optional<std::string> breakpoint, bool hasAdaptiveThemes, ColorScheme colorScheme, Dimensions screen, std::string contentSizeCategory, Insets insets, double pixelRatio, double fontScale, bool rtl, Dimensions statusBar, Dimensions navigationBar, bool isPortrait, bool isLandscape): themeName(themeName), breakpoint(breakpoint), hasAdaptiveThemes(hasAdaptiveThemes), colorScheme(colorScheme), screen(screen), contentSizeCategory(contentSizeCategory), insets(insets), pixelRatio(pixelRatio), fontScale(fontScale), rtl(rtl), statusBar(statusBar), navigationBar(navigationBar), isPortrait(isPortrait), isLandscape(isLandscape) {}
  };

} // namespace margelo::nitro::unistyles

namespace margelo::nitro {

  using namespace margelo::nitro::unistyles;

  // C++ UnistylesCxxMiniRuntime <> JS UnistylesCxxMiniRuntime (object)
  template <>
  struct JSIConverter<UnistylesCxxMiniRuntime> final {
    static inline UnistylesCxxMiniRuntime fromJSI(jsi::Runtime& runtime, const jsi::Value& arg) {
      jsi::Object obj = arg.asObject(runtime);
      return UnistylesCxxMiniRuntime(
        JSIConverter<std::optional<std::string>>::fromJSI(runtime, obj.getProperty(runtime, "themeName")),
        JSIConverter<std::optional<std::string>>::fromJSI(runtime, obj.getProperty(runtime, "breakpoint")),
        JSIConverter<bool>::fromJSI(runtime, obj.getProperty(runtime, "hasAdaptiveThemes")),
        JSIConverter<ColorScheme>::fromJSI(runtime, obj.getProperty(runtime, "colorScheme")),
        JSIConverter<Dimensions>::fromJSI(runtime, obj.getProperty(runtime, "screen")),
        JSIConverter<std::string>::fromJSI(runtime, obj.getProperty(runtime, "contentSizeCategory")),
        JSIConverter<Insets>::fromJSI(runtime, obj.getProperty(runtime, "insets")),
        JSIConverter<double>::fromJSI(runtime, obj.getProperty(runtime, "pixelRatio")),
        JSIConverter<double>::fromJSI(runtime, obj.getProperty(runtime, "fontScale")),
        JSIConverter<bool>::fromJSI(runtime, obj.getProperty(runtime, "rtl")),
        JSIConverter<Dimensions>::fromJSI(runtime, obj.getProperty(runtime, "statusBar")),
        JSIConverter<Dimensions>::fromJSI(runtime, obj.getProperty(runtime, "navigationBar")),
        JSIConverter<bool>::fromJSI(runtime, obj.getProperty(runtime, "isPortrait")),
        JSIConverter<bool>::fromJSI(runtime, obj.getProperty(runtime, "isLandscape"))
      );
    }
    static inline jsi::Value toJSI(jsi::Runtime& runtime, const UnistylesCxxMiniRuntime& arg) {
      jsi::Object obj(runtime);
      obj.setProperty(runtime, "themeName", JSIConverter<std::optional<std::string>>::toJSI(runtime, arg.themeName));
      obj.setProperty(runtime, "breakpoint", JSIConverter<std::optional<std::string>>::toJSI(runtime, arg.breakpoint));
      obj.setProperty(runtime, "hasAdaptiveThemes", JSIConverter<bool>::toJSI(runtime, arg.hasAdaptiveThemes));
      obj.setProperty(runtime, "colorScheme", JSIConverter<ColorScheme>::toJSI(runtime, arg.colorScheme));
      obj.setProperty(runtime, "screen", JSIConverter<Dimensions>::toJSI(runtime, arg.screen));
      obj.setProperty(runtime, "contentSizeCategory", JSIConverter<std::string>::toJSI(runtime, arg.contentSizeCategory));
      obj.setProperty(runtime, "insets", JSIConverter<Insets>::toJSI(runtime, arg.insets));
      obj.setProperty(runtime, "pixelRatio", JSIConverter<double>::toJSI(runtime, arg.pixelRatio));
      obj.setProperty(runtime, "fontScale", JSIConverter<double>::toJSI(runtime, arg.fontScale));
      obj.setProperty(runtime, "rtl", JSIConverter<bool>::toJSI(runtime, arg.rtl));
      obj.setProperty(runtime, "statusBar", JSIConverter<Dimensions>::toJSI(runtime, arg.statusBar));
      obj.setProperty(runtime, "navigationBar", JSIConverter<Dimensions>::toJSI(runtime, arg.navigationBar));
      obj.setProperty(runtime, "isPortrait", JSIConverter<bool>::toJSI(runtime, arg.isPortrait));
      obj.setProperty(runtime, "isLandscape", JSIConverter<bool>::toJSI(runtime, arg.isLandscape));
      return obj;
    }
    static inline bool canConvert(jsi::Runtime& runtime, const jsi::Value& value) {
      if (!value.isObject()) {
        return false;
      }
      jsi::Object obj = value.getObject(runtime);
      if (!JSIConverter<std::optional<std::string>>::canConvert(runtime, obj.getProperty(runtime, "themeName"))) return false;
      if (!JSIConverter<std::optional<std::string>>::canConvert(runtime, obj.getProperty(runtime, "breakpoint"))) return false;
      if (!JSIConverter<bool>::canConvert(runtime, obj.getProperty(runtime, "hasAdaptiveThemes"))) return false;
      if (!JSIConverter<ColorScheme>::canConvert(runtime, obj.getProperty(runtime, "colorScheme"))) return false;
      if (!JSIConverter<Dimensions>::canConvert(runtime, obj.getProperty(runtime, "screen"))) return false;
      if (!JSIConverter<std::string>::canConvert(runtime, obj.getProperty(runtime, "contentSizeCategory"))) return false;
      if (!JSIConverter<Insets>::canConvert(runtime, obj.getProperty(runtime, "insets"))) return false;
      if (!JSIConverter<double>::canConvert(runtime, obj.getProperty(runtime, "pixelRatio"))) return false;
      if (!JSIConverter<double>::canConvert(runtime, obj.getProperty(runtime, "fontScale"))) return false;
      if (!JSIConverter<bool>::canConvert(runtime, obj.getProperty(runtime, "rtl"))) return false;
      if (!JSIConverter<Dimensions>::canConvert(runtime, obj.getProperty(runtime, "statusBar"))) return false;
      if (!JSIConverter<Dimensions>::canConvert(runtime, obj.getProperty(runtime, "navigationBar"))) return false;
      if (!JSIConverter<bool>::canConvert(runtime, obj.getProperty(runtime, "isPortrait"))) return false;
      if (!JSIConverter<bool>::canConvert(runtime, obj.getProperty(runtime, "isLandscape"))) return false;
      return true;
    }
  };

} // namespace margelo::nitro
