// PspGetNextChildJob 
 
_DWORD *__fastcall PspGetNextChildJob(int a1, int a2)
{
  int v4; // r3
  unsigned int v5; // r5
  _DWORD *v6; // r8
  _DWORD *v7; // r4
  int v8; // r0
  __int16 v9; // r3

  v4 = __mrc(15, 0, 13, 0, 3);
  v5 = v4 & 0xFFFFFFC0;
  v6 = 0;
  if ( (v4 & 0xFFFFFFC0) != 0 )
    --*(_WORD *)((v4 & 0xFFFFFFC0) + 0x136);
  ExAcquireResourceSharedLite(a1 + 32, 1);
  if ( a2 )
    v7 = *(_DWORD **)(a2 + 556);
  else
    v7 = *(_DWORD **)(a1 + 564);
  while ( v7 != (_DWORD *)(a1 + 564) )
  {
    if ( ObReferenceObjectSafeWithTag((int)(v7 - 139)) )
    {
      v6 = v7 - 139;
      break;
    }
    v7 = (_DWORD *)*v7;
  }
  v8 = ExReleaseResourceLite(a1 + 32);
  if ( v5 )
  {
    v9 = *(_WORD *)(v5 + 310) + 1;
    *(_WORD *)(v5 + 310) = v9;
    if ( !v9 && *(_DWORD *)(v5 + 100) != v5 + 100 )
      KiCheckForKernelApcDelivery(v8);
  }
  if ( a2 )
    ObfDereferenceObjectWithTag(a2);
  return v6;
}
