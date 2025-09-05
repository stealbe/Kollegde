# Сообщение для коммита
$commitMessage = "Обновление: 05.09.25"

# Получаем пути всех рабочих директорий (worktrees)
$worktrees = git worktree list | ForEach-Object {
    ($_ -split '\s{2,}', 2)[0].Trim()
}

foreach ($wt in $worktrees) {
    if (Test-Path $wt) {
        Write-Host "Работаю с $wt"
        Set-Location $wt

        # Добавляем все изменения
        git add -A

        # Коммитим, если есть изменения
        git diff --cached --quiet
        if ($LASTEXITCODE -ne 0) {
            git commit -m "$commitMessage"
            Write-Host "Закоммичено в $wt"
        } else {
            Write-Host "Нет изменений для коммита в $wt"
        }
    } else {
        Write-Host "Папка не найдена: $wt"
    }
}

# Пушим все ветки
git push --all origin
Write-Host "Все ветки запушены!"
