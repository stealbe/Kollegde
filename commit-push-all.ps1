# commit-push-all.ps1
$commitMessage = "Автообновление: $(Get-Date -Format 'dd.MM.yyyy HH:mm')"

# Получаем все worktree (главная + дополнительные)
$worktrees = git worktree list | ForEach-Object { ($_ -split '\s+')[0] }

foreach ($wt in $worktrees) {
    Write-Host ">>> Работаю с $wt ..."
    
    # Заходим в папку worktree, оборачивая путь в кавычки
    Set-Location "$wt"

    git add .

    # Коммитим только если есть изменения
    $result = git commit -m "$commitMessage" 2>&1
    if ($LASTEXITCODE -eq 0) {
        Write-Host "✔ Закоммичено в $wt"
    } else {
        Write-Host "ℹ Нет изменений в $wt"
    }

    # Возвращаемся в основную папку репо
    Set-Location "E:\Kolledge\2 course"
}

# Пушим все ветки сразу
git push --all origin
Write-Host ">>> Все ветки запушены!"
