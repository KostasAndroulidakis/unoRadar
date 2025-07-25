#ifndef SIREN_THEME_H
#define SIREN_THEME_H

// SIREN Theme Manager
// Single Responsibility: Apply Styling
// Compliant with MISRA C++ 2023, SRP, SSOT

#include <QWidget>
#include <QString>
#include <QColor>

namespace siren {
namespace ui {

/**
 * @brief Theme manager - Single Responsibility: Apply Styling
 *
 * This class has ONE job: Apply consistent styling to widgets.
 * It does NOT create widgets, manage layouts, or handle widget behavior.
 *
 * Color Scheme:
 * - Primary Background: Black (#000000)
 * - Primary Accent: Cyan (#00FFFF) - main interactive elements
 * - Secondary Accent: Orange-Red (#FF4500) - warnings, highlights
 * - Text: White (#FFFFFF) on dark backgrounds
 * - Borders: Cyan for active, dark gray for inactive
 *
 * MISRA C++ Compliance:
 * - Rule 5.0.1: No magic numbers (all colors defined as constants)
 * - Rule 2.10.1: All constants shall be used
 */
class Theme final
{
public:
    /**
     * @brief Apply theme to main application
     * @param app Application instance to style
     */
    static void applyToApplication(QWidget* app);

    /**
     * @brief Apply status panel styling
     * @param panel Status panel widget
     */
    static void applyStatusPanelStyle(QWidget* panel);

    /**
     * @brief Apply control panel styling
     * @param panel Control panel widget
     */
    static void applyControlPanelStyle(QWidget* panel);

    /**
     * @brief Apply sonar display styling
     * @param panel Sonar display widget
     */
    static void applySonarPanelStyle(QWidget* panel);

    /**
     * @brief Apply data panel styling
     * @param panel Data panel widget
     */
    static void applyDataPanelStyle(QWidget* panel);

    /**
     * @brief Apply performance panel styling
     * @param panel Performance panel widget
     */
    static void applyPerformancePanelStyle(QWidget* panel);

    /**
     * @brief Apply connection indicator styling
     * @param widget Connection status widget
     */
    static void applyConnectionIndicatorStyle(QWidget* widget);

    /**
     * @brief Apply button styling (primary cyan)
     * @param button Button widget
     */
    static void applyPrimaryButtonStyle(QWidget* button);

    /**
     * @brief Apply button styling (secondary orange)
     * @param button Button widget
     */
    static void applySecondaryButtonStyle(QWidget* button);

    /**
     * @brief Apply danger button styling (red)
     * @param button Button widget
     */
    static void applyDangerButtonStyle(QWidget* button);

    /**
     * @brief Get complete stylesheet
     * @return Complete CSS stylesheet string
     */
    [[nodiscard]] static QString getStyleSheet();

    // Color accessors for QPalette setup (SSOT compliance)
    [[nodiscard]] static QColor getPrimaryBackground();
    [[nodiscard]] static QColor getMilitaryGreen();
    [[nodiscard]] static QColor getAlternateRow();
    [[nodiscard]] static QColor getPrimaryText();

private:
    // Static class - no instantiation
    Theme() = delete;
    ~Theme() = delete;
    Theme(const Theme&) = delete;
    Theme& operator=(const Theme&) = delete;

    // Color constants (SSOT for all colors)
    static constexpr const char* PRIMARY_BACKGROUND = "#000000";    // Black
    static constexpr const char* SECONDARY_BACKGROUND = "#1a1a1a";  // Dark gray
    static constexpr const char* PANEL_BACKGROUND = "#0d0d0d";      // Very dark gray

    static constexpr const char* PRIMARY_ACCENT = "#00FFFF";        // Cyan (main color)
    static constexpr const char* SECONDARY_ACCENT = "#FF4500";      // Orange-red
    static constexpr const char* SECONDARY_PRESSED = "#CC3300";     // Dark orange-red (pressed)
    static constexpr const char* SUCCESS_COLOR = "#00FF00";         // Green (connected)
    static constexpr const char* DANGER_COLOR = "#FF0000";          // Red (disconnected)
    static constexpr const char* DANGER_PRESSED = "#CC0000";        // Dark red (pressed)
    static constexpr const char* WARNING_COLOR = "#FFFF00";         // Yellow (warning)

    static constexpr const char* PRIMARY_TEXT = "#FFFFFF";          // White text
    static constexpr const char* MILITARY_GREEN = "#00FF41";        // Military green (RGB: 0, 255, 65)
    static constexpr const char* SECONDARY_TEXT = "#CCCCCC";        // Light gray text
    static constexpr const char* DISABLED_TEXT = "#666666";         // Dark gray text
    static constexpr const char* ALTERNATE_ROW = "#1F1F1F";         // Alternate row color (RGB: 31, 31, 31)

    static constexpr const char* BORDER_ACTIVE = "#00FFFF";         // Cyan border (active)
    static constexpr const char* BORDER_INACTIVE = "#333333";       // Dark gray border
    static constexpr const char* BORDER_HOVER = "#00DDDD";          // Lighter cyan (hover)

    static constexpr const char* MONOSPACE_FONT = "'Courier New', monospace";
};

} // namespace ui
} // namespace siren

#endif // SIREN_THEME_H