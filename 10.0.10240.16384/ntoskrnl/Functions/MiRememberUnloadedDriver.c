// MiRememberUnloadedDriver 
 
unsigned __int16 *__fastcall MiRememberUnloadedDriver(unsigned __int16 *result, int a2, int a3)
{
  unsigned __int16 *v3; // r7
  unsigned int v6; // r4
  int v7; // r3
  int v8; // r0
  int v9; // r2
  int v10; // r5
  int v11; // r0
  unsigned __int16 v12; // r3
  __int16 v13; // r3
  _BYTE *v14; // r0

  v3 = result;
  if ( !*result )
    return result;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(__int16 *)(v6 + 0x134) - 1;
  *(_WORD *)(v6 + 308) = v7;
  ExAcquireResourceExclusiveLite((int)&PsLoadedModuleResource, 1, a3, v7);
  v8 = dword_634F88;
  if ( dword_634F88 )
  {
    v9 = dword_634F84;
    if ( (unsigned int)dword_634F84 >= 0x32 )
      return (unsigned __int16 *)sub_7CEA08();
  }
  else
  {
    v14 = (_BYTE *)ExAllocatePoolWithTag(512, 1200, 1413770573);
    dword_634F88 = (int)v14;
    if ( !v14 )
      goto LABEL_7;
    memset(v14, 0, 1200);
    v9 = 0;
    dword_634F84 = 0;
    v8 = dword_634F88;
  }
  v10 = v8 + 24 * v9;
  RtlFreeAnsiString((_DWORD *)v10);
  v11 = ExAllocatePoolWithTag(512, *v3, 1413770573);
  *(_DWORD *)(v10 + 4) = v11;
  if ( v11 )
  {
    memmove(v11, *((_DWORD *)v3 + 1), *v3);
    *(_WORD *)v10 = *v3;
    v12 = v3[1];
    *(_DWORD *)(v10 + 8) = a2;
    *(_WORD *)(v10 + 2) = v12;
    *(_DWORD *)(v10 + 12) = a2 + a3;
    KeQuerySystemTime((_DWORD *)(v10 + 16));
    ++dword_634F84;
  }
  else
  {
    *(_WORD *)(v10 + 2) = 0;
    *(_WORD *)v10 = 0;
  }
LABEL_7:
  result = (unsigned __int16 *)ExReleaseResourceLite((int)&PsLoadedModuleResource);
  v13 = *(_WORD *)(v6 + 308) + 1;
  *(_WORD *)(v6 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    result = (unsigned __int16 *)KiCheckForKernelApcDelivery((int)result);
  return result;
}
