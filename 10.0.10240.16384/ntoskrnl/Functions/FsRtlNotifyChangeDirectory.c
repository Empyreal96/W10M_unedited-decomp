// FsRtlNotifyChangeDirectory 
 
int __fastcall FsRtlNotifyChangeDirectory(int a1, int a2, unsigned __int16 *a3, _DWORD *a4, char a5, int a6, _DWORD *a7)
{
  return FsRtlNotifyFilterChangeDirectory(a1, a4, a2, a3, a5, 1, a6, a7, 0, 0, 0);
}
