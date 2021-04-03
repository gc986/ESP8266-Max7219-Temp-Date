# ESP8266-Max7219-Temp-Date
Загрузка времени и погоды через WiFi с помощью ESP8266, отображение при помощи дисплея построенном на MAX7219


Проект разрабатывается на платформе <b>PlatformIO</b>. Для модификации рекомендуется использовать IDE VisualCode.


Для правильного подключения к вашей сети WiFi, нужно указать правильные имя сети (ssid) и пароль (pass) в файле main.cpp.

Чтобы иметь возможность получать погоду, нужно указать ваш appid (openweathermap.org), который располагается в строке подключения к серверу weatherServerUrl, в файле WeatherRout.h. Там же вы можете уточнить название вашего населённого пункта (по умолчанию указан город Екатеринбург).
