# commit-all.ps1
$commitMessage = "Автообновление: %date% %time%"

# Получаем список worktree и их пути
$worktrees = git worktree list | ForEach-Object { ($_ -split '\s+')[0] }

foreach ($wt in $worktrees) {
    Write-Host ">>> Работаю с $wt ..."
    Set-Location "$wt"  # <- вот здесь кавычки

    git add .
    $result = git commit -m "$commitMessage" 2>&1
    if ($LASTEXITCODE -eq 0) {
        Write-Host "✔ Закоммичено в $wt"
    } else {
        Write-Host "ℹ Нет изменений в $wt"
    }

    Set-Location "E:\Kolledge\2 course"
}
git push --all origin
Write-Host ">>> Все ветки запушены!"
