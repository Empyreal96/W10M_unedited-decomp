// CmpUnlockHiveFlusher 
 
int __fastcall CmpUnlockHiveFlusher(int a1)
{
  return ExReleaseResourceLite(*(_DWORD *)(a1 + 1872));
}
