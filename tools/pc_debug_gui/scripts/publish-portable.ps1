param(
    [string]$Runtime = "win-x64",
    [string]$Configuration = "Release"
)

$ErrorActionPreference = "Stop"

$RepoRoot = Resolve-Path (Join-Path $PSScriptRoot "../")
$SrcRoot = Join-Path $RepoRoot "src"
$Project = Join-Path $SrcRoot "PcDebugGui.App/PcDebugGui.App.csproj"
$Output = Join-Path $RepoRoot ("dist/{0}" -f $Runtime)

if (Test-Path $Output) {
    Remove-Item -Path $Output -Recurse -Force
}

Write-Host "Publishing $Project -> $Output"
dotnet publish $Project `
    -c $Configuration `
    -r $Runtime `
    --self-contained false `
    -p:PublishSingleFile=true `
    -p:IncludeNativeLibrariesForSelfExtract=true `
    -o $Output

New-Item -ItemType Directory -Path (Join-Path $Output "sessions") -Force | Out-Null
Copy-Item -Path (Join-Path $RepoRoot "config/appsettings.json") -Destination (Join-Path $Output "appsettings.json")

Write-Host "Portable package ready at: $Output"
