Write-Host -NoNewline "��ȷ����";
Write-Host -NoNewline -ForegroundColor Yellow "����Ա�������";
Write-Host -NoNewline "�������������";
Write-Host -NoNewline -ForegroundColor Yellow "���������";
Write-Host "��";
Write-Host -NoNewline "������(Y/N)";
$usrinput = Read-Host;
if ($usrinput -eq 'n' -or $usrinput -eq 'N'){
    exit;
}
Write-Host;

# �Ȱ�װChoco
Write-Host "==========";
Write-Host -ForegroundColor Green "��װ Chocolatey";
Write-Host "==========";
Set-ExecutionPolicy AllSigned;
Set-ExecutionPolicy Bypass -Scope Process -Force; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'));
SET "PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin";
Write-Host;


