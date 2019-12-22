Write-Host -NoNewline "请确保以";
Write-Host -NoNewline -ForegroundColor Yellow "管理员身份运行";
Write-Host -NoNewline "，并已配置完毕";
Write-Host -NoNewline -ForegroundColor Yellow "代理服务器";
Write-Host "。";
Write-Host -NoNewline "继续吗？(Y/N)";
$usrinput = Read-Host;
if ($usrinput -eq 'n' -or $usrinput -eq 'N'){
    exit;
}
Write-Host;

# 先安装Choco
Write-Host "==========";
Write-Host -ForegroundColor Green "安装 Chocolatey";
Write-Host "==========";
Set-ExecutionPolicy AllSigned;
Set-ExecutionPolicy Bypass -Scope Process -Force; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'));
SET "PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin";
Write-Host;


