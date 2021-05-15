// FsFilterPerformCompletionCallbacks 
 
int __fastcall FsFilterPerformCompletionCallbacks(int result, int a2)
{
  int v2; // r5
  int v4; // r4
  __int16 v5; // r2

  v2 = result;
  if ( *(_WORD *)(result + 46) )
  {
    do
    {
      v4 = *(_DWORD *)(v2 + 48) + 16 * *(unsigned __int16 *)(v2 + 46);
      *(_DWORD *)(v2 + 8) = *(_DWORD *)(v4 - 16);
      *(_DWORD *)(v2 + 12) = *(_DWORD *)(v4 - 12);
      result = (*(int (__fastcall **)(int, int, _DWORD))(v4 - 4))(v2, a2, *(_DWORD *)(v4 - 8));
      v5 = *(_WORD *)(v2 + 46) - 1;
      *(_WORD *)(v2 + 46) = v5;
    }
    while ( v5 );
  }
  return result;
}
