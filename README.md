# Опис застосунку:  
  цей код є програмою для перетворення тексту з формату Markdown у формат HTML. Вона використовує регулярні вирази для пошуку різних елементів розмітки Markdown, такі як жирний,   
курсив, преформатований та параграфи. І замінює їх відповідними HTML-тегами.  

# Інструкція як зібрати та запустити проект:  
## Збірка проекту:  
1.Відкрийте інтегроване середовище розробки призначене для с++, наприклад Visual Studio Code, CLion, або будь-яке інше, яке ви використовуєте.  
2.Створіть новий проект або відкрийте існуючий, якщо такий вже існує.  
3.Додайте файли з кодом до проекту (файли main.cpp).  
4.Переконайтеся, що ваш проект має підключення до бібліотеки C++ iostream, fstream, sstream, string, vector, regex.  
5.Здійсніть збірку проекту за допомогою функціоналу вашої IDE або використовуючи команду компіляції вашого компілятора.   

## Запуск проекту:  
1.Переконайтеся, що у вас є файл з вхідним текстом у форматі Markdown, який ви бажаєте перетворити.  
2.Запустіть зібраний виконуваний файл програми з командного рядка, передавши шлях до вхідного файлу як аргумент командного рядка, наприклад: D:\GitBasics\x64\Debug\GitBasics.exe C:\Users\User\Desktop\test.txt.  
3.Якщо ви бажаєте також зберегти результат у файлі HTML, вказуйте шлях до вихідного файлу, наприклад: D:\GitBasics\x64\Debug\GitBasics.exe C:\Users\User\Desktop\test.txt > C:\Users\User\Desktop\example.html.  

# Інструкція до використання проекту:  
1.Після запуску програма перетворить вміст вхідного файлу у форматі Markdown у відповідний формат HTML.  
2.Якщо ви використовуєте командний рядок для запуску програми, впевніться, що передаєте правильний шлях до вхідного файлу, а також, за необхідності, шлях до вихідного файлу, якщо ви хочете зберегти результат.  
3.Програма виведе результат у консоль або збереже у вказаному файлі HTML, залежно від того, чи вказаний шлях до вихідного файлу.  

# Revert-коміт:  
Дата: Mar 17, 2024.  
Хеш-коміту: 8f2c29b.  
Назва: Добавлена функція читання україномовних файлів.  
Опис змін: добавлена частина коду обробки файлів українською мовою, включаючи читання і запис файлів з кодуванням UTF-8.   
Причина реверту: виникли проблеми у коді через кодування, хоча була включена бібліотека local, але все одно компілятор показував помилки на дописані частини коду.    
