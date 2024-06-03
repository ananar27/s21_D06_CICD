
# Report by ananar27

## Part 1 Установка Girlab-Runner
- Целью задания было установить утилиту gitlab-runner на виртуальную машину ubuntu server 22.04 LTS.
    - Для этого скачаем дистрибутив необходимой версии ubuntu server и установим его:

    ![img/part1-1.png](img/part1-1.png)  
    *текущая версия системы*  

    - Устанавливаем gitlab-runner на виртуальной машине при помоще следующих команд:

    ![img/part1-2.png](img/part1-2.png)

    - Запускаем `sudo gitlab-runner register`
    ![img/part1-3.png](img/part1-3.png)

    Важно указать верный тэг для дальнейшей работы ы gitlab-runner, иначе цели не будут выполнены  утилита будет выдавать ошибку.
    
    - Запускаем `sudo gitlab-runner run`

    ![img/part1-4.png](img/part1-4.png)

## Part 2 Сборка
- Целью задания было написать этап для CI по сборке приложений из проекта C2_SimpleBashUtils:
    - В файле gitlab-ci.yml добавить этап запуска сборки через makefile из проекта C2. Файлы, полученные после сборки (артефакты), сохранять в произвольную директорию со сроком хранения 30 дней.
    
    ![img/part2-1.png](img/part2-1.png)
    
    *НЕ ДЕЛАЙТЕ ТАК, прописанные здесь тэги не были указаны ранее при регисрации gitlab-runner*  

    Tag `ci/cd` был прописан мной при регистарции gitlab-runner, и все заработала только при его использовании
    
    ![img/part2-3.png](img/part2-3.png)

    ![img/part2-2.png](img/part2-2.png)  
    ![img/part2-4.png](img/part2-4.png)
    *вывод результатов сборки*  

## Part 3 Тест кодстайла
- Целью задания было написать этап для **CI**, который запускает скрипт кодстайла (*clang-format*):
    - следующие изменения были внесены в .gitlab-ci.yml файл:
    
    ![img/part3-1.png](img/part3-1.png)
   
    - создаем bash скрипт style_test.sh:
    
    ![img/part3-2.png](img/part3-2.png)
    
    - проект не прошел проверку, фейлим пайплайн:
    
    ![img/part3-3.png](img/part3-3.png)
    
    - вывод утилиты *clang-format*:
    
    ![img/part3-4.png](img/part3-4.png)
    
    - проект прошел проверку:
    
    ![img/part3-5.png](img/part3-5.png)
    
    - вывод утилиты *clang-format*:
    
    ![img/part3-6.png](img/part3-6.png)

## Part 4. Интеграционные тесты
- Целью задания было написать этап для **CI**, который запускает интеграционные тесты из того же проекта:
    - следующие изменения были внесены в .gitlab-ci.yml файл:
    
    ![img/part4-1.png](img/part4-1.png)
    
    - создаем bash скрипт unit_test.sh:
    
    ![img/part4-2.png](img/part4-2.png)
   
    - данный этап должен запускатьсяавтоматически только при условии, если сборка и тест кодстайла прошли успешно:
    
    ![img/part4-3.png](img/part4-3.png)
    
    - в пайплайне отобразить, что интеграционные тесты успешно прошли / провалились:
    
    ![img/part4-4-1.png](img/part4-4-1.png)
    ![img/part4-4-2.png](img/part4-4-2.png)
    ![img/part4-4-3.png](img/part4-4-3.png)

### Part 5. Этап деплоя
- Целью задания было написать этап для **CI**, который запускает деплой приложений из проекта C2_SimpleBashUtils:
    - следующие изменения были внесены в .gitlab-ci.yml файл:
    
    ![img/part5-0.png](img/part5-0.png)
    
    - создаем вторую виртуальную машину, настраиваем параметры сети

    ![img/part5-1.png](img/part5-1.png)

    - проверяем, пингуются ли машины

    ![img/part5-2.png](img/part5-2.png)

    - создаем ssh ключ для второго пользователя в gitlab-runner на виртуальной машине ci21 и настроим доступ по ssh.
    ```
    sudo su gitlab-runner
    ssh-keygen -t rsa -b 2048
    ssh-copy-id raffordg@192.168.100.11
    ssh  raffordg@192.168.100.11
    ```
    - На виртуальной машине cd21 так же создадим ключ и настроим доступ.
    ```
    ssh-keygen -t rsa -b 2048
    ssh-copy-id  raffordg@192.168.100.10
    sudo chown -R $(whoami) /usr/local/bin
    ```
    - создаем bash скрипт deploy_script.sh:
    
    ![img/bash-script.png](img/bash-script.png)

    - пушим наш код с дополнением в виде deply_script.sh

    ![img/part5-3.png](img/part5-3.png)
    ![img/part5-4.png](img/part5-4.png)
