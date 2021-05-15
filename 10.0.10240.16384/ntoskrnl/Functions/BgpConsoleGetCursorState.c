// BgpConsoleGetCursorState 
 
int __fastcall BgpConsoleGetCursorState(_DWORD *a1, _DWORD *a2, _DWORD *a3)
{
  BgpFwAcquireLock((unsigned int)a1);
  *a1 = dword_610384;
  *a2 = dword_610388;
  *a3 = dword_61038C;
  BgpFwReleaseLock();
  return 0;
}
