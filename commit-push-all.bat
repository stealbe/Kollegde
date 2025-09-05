@echo off
set commitMessage=Автообновление: %date% %time%

rem Проходим по всем worktree
for /f "tokens=1" %%i in ('git worktree list ^| findstr /R "^[A-Z]:\\"') do (
    echo >>> Работаю с %%i ...
    pushd "%%i"
    git add .
    git commit -m "%commitMessage%" >nul 2>&1
    if %ERRORLEVEL%==0 (
        echo ✔ Закоммичено в %%i
    ) else (
        echo ℹ Нет изменений в %%i
    )
    popd
)

git push --all origin
echo >>> Все ветки запушены!
pause
