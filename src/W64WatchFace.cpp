#include "W64WatchFace.h"

#define DARKMODE false

void W64WatchFace::drawWatchFace()
{
    display.fillScreen(DARKMODE ? GxEPD_BLACK : GxEPD_WHITE);
    display.setTextColor(DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
    drawTime();
    drawDate();
}

void W64WatchFace::drawTime()
{
    display.setFont(&C64_Pro_Mono_STYLE18pt7b);
    display.setCursor(10, 53 + 5);

    display.printf("%02i:%02i", currentTime.Hour, currentTime.Minute);
}

void W64WatchFace::drawDate()
{
    weatherData currentWeather = getWeatherData();
    int8_t temperature = currentWeather.temperature;

    display.setFont(&C64_Pro_Mono_STYLE6pt7b);
    display.setCursor(0, 85);

    display.print("LIST\n");
    display.print("\n");
    display.printf(" 1 \"%s   \"  PRG\n", strupr(dayShortStr(currentTime.Wday)));
    display.printf(" 2 \"%02i %s\"  PRG\n", currentTime.Day, strupr(monthShortStr(currentTime.Month)));
    display.printf(" 3 \"%i  \"  PRG\n", currentTime.Year + YEAR_OFFSET);
    display.printf(" 4 \"S%05i\"  PRG\n", sensor.getCounter());
    display.printf(" 5 \"T%s%02i  \"  PRG\n", (temperature < 0 ? "-" : " "), (uint8_t)abs(temperature));

    if (currentWeather.weatherConditionCode > 801)
    {
        display.print(" 6 \"CLOUDY\"  PRG\n");
    }
    else if (currentWeather.weatherConditionCode == 801)
    {
        display.print(" 6 \"FCLOUD\"  PRG\n");
    }
    else if (currentWeather.weatherConditionCode == 800)
    {
        display.print(" 6 \"CLEAR \"  PRG\n");
    }
    else if (currentWeather.weatherConditionCode >= 700)
    {
        display.print(" 6 \"CLOUDY\"  PRG\n");
    }
    else if (currentWeather.weatherConditionCode >= 600)
    {
        display.print(" 6 \"SNOW  \"  PRG\n");
    }
    else if (currentWeather.weatherConditionCode >= 500)
    {
        display.print(" 6 \"RAIN  \"  PRG\n");
    }
    else if (currentWeather.weatherConditionCode >= 300)
    {
        display.print(" 6 \"RAIN  \"  PRG\n");
    }
    else if (currentWeather.weatherConditionCode >= 200)
    {
        display.print(" 6 \"THUNDE\"  PRG\n");
    }

    display.print("644 BLOCKS FREE.\n");
    display.print("READY.\n");
}
