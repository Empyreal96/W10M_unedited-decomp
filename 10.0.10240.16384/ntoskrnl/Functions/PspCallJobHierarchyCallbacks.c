// PspCallJobHierarchyCallbacks 
 
int __fastcall PspCallJobHierarchyCallbacks(int a1, int (__fastcall *a2)(int, int), int a3, int a4, int a5, char a6)
{
  int (__fastcall *v6)(_DWORD *, int); // r9
  int (__fastcall *v7)(int, int); // r8
  int v10; // r5
  unsigned int v11; // r4
  _DWORD *i; // r6
  int v13; // r0
  __int16 v14; // r3

  v6 = (int (__fastcall *)(_DWORD *, int))a4;
  v7 = (int (__fastcall *)(int, int))a3;
  v10 = 0;
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( !a2 && !a4 )
    goto LABEL_19;
  if ( (a6 & 1) == 0 )
  {
    if ( (a6 & 4) != 0 )
    {
      if ( v11 )
      {
        a4 = *(__int16 *)(v11 + 310) - 1;
        *(_WORD *)(v11 + 310) = a4;
      }
      ExAcquireResourceExclusiveLite(a1 + 32, 1, a3, a4);
    }
    else
    {
      if ( v11 )
        --*(_WORD *)(v11 + 310);
      ExAcquireResourceSharedLite(a1 + 32, 1);
    }
  }
  if ( !a2 || (v10 = a2(a1, a5), v10 >= 0) )
  {
    if ( v6 )
    {
      for ( i = *(_DWORD **)(a1 + 24); i != (_DWORD *)(a1 + 24); i = (_DWORD *)*i )
      {
        v10 = v6(i - 96, a5);
        if ( v10 < 0 )
          break;
      }
      v7 = (int (__fastcall *)(int, int))a3;
    }
  }
  if ( (a6 & 1) == 0 )
  {
    v13 = ExReleaseResourceLite(a1 + 32);
    if ( v11 )
    {
      v14 = *(_WORD *)(v11 + 310) + 1;
      *(_WORD *)(v11 + 310) = v14;
      if ( !v14 && *(_DWORD *)(v11 + 100) != v11 + 100 )
        KiCheckForKernelApcDelivery(v13);
    }
  }
  if ( v10 < 0 )
  {
    if ( v10 == -1073741536 )
      v10 = 0;
  }
  else
  {
LABEL_19:
    if ( v7 )
      v10 = v7(a1, a5);
  }
  return v10;
}
