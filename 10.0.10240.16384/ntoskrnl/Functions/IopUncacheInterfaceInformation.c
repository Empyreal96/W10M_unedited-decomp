// IopUncacheInterfaceInformation 
 
int __fastcall IopUncacheInterfaceInformation(int result, int a2)
{
  int v3; // r4
  unsigned int v4; // r2
  int v5; // r4
  _DWORD *v6; // r5
  _DWORD *v7; // r7
  unsigned int v8; // r1
  int v9; // r3
  unsigned int v10; // r8
  unsigned int v11; // r9

  v3 = result;
  if ( a2 )
  {
    v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v4 + 308);
    result = KeWaitForSingleObject((unsigned int)&PpRegistrySemaphore, 4, 0, 0, 0);
  }
  if ( v3 )
    v5 = *(_DWORD *)(*(_DWORD *)(v3 + 176) + 20);
  else
    v5 = 0;
  if ( *(_DWORD *)(v5 + 328) != v5 + 328 )
    return sub_7E0C4C();
  v6 = (_DWORD *)(v5 + 336);
  v7 = *(_DWORD **)(v5 + 336);
  if ( v7 != (_DWORD *)(v5 + 336) )
  {
    do
    {
      v10 = v7[3];
      v11 = (unsigned int)v7;
      if ( v10 )
      {
        (*(void (__fastcall **)(_DWORD))(v10 + 12))(*(_DWORD *)(v10 + 4));
        ExFreePoolWithTag(v10);
      }
      v7 = (_DWORD *)*v7;
      result = ExFreePoolWithTag(v11);
    }
    while ( v7 != v6 );
  }
  *(_DWORD *)(v5 + 328) = v5 + 328;
  *(_DWORD *)(v5 + 332) = v5 + 328;
  *v6 = v6;
  *(_DWORD *)(v5 + 340) = v5 + 336;
  *(_WORD *)(v5 + 348) = 0;
  *(_WORD *)(v5 + 350) = 0;
  *(_WORD *)(v5 + 344) = 0;
  *(_WORD *)(v5 + 346) = 0;
  if ( a2 )
  {
    result = KeReleaseSemaphore((int)&PpRegistrySemaphore, 0, 1);
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v9 = (__int16)(*(_WORD *)(v8 + 0x134) + 1);
    *(_WORD *)(v8 + 308) = v9;
    if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
