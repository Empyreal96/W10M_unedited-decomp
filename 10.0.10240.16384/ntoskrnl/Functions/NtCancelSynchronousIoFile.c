// NtCancelSynchronousIoFile 
 
int __fastcall NtCancelSynchronousIoFile(int a1, int a2, unsigned int a3, int a4)
{
  _DWORD *v4; // r6
  char v6; // lr
  _DWORD *v7; // r4
  int v8; // r4
  unsigned __int64 *v9; // r3
  unsigned __int64 v10; // kr00_8
  unsigned int *v11; // r2
  unsigned int v12; // r1
  int v13; // r5
  int _10[14]; // [sp+10h] [bp-20h] BYREF

  _10[13] = a4;
  _10[0] = a3;
  _10[1] = a4;
  v4 = (_DWORD *)a3;
  _10[12] = a3;
  _10[11] = a2;
  _10[10] = a1;
  v6 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v6 )
  {
    v7 = (_DWORD *)a3;
    if ( a3 >= MmUserProbeAddress )
      v7 = (_DWORD *)MmUserProbeAddress;
    *v7 = *v7;
  }
  v8 = ObReferenceObjectByHandle(a1, 1, PsThreadType, v6, (int)_10, 0);
  if ( v8 >= 0 )
  {
    if ( IoCountOperations == 1 )
    {
      v9 = (unsigned __int64 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) + 448);
      do
        v10 = __ldrexd(v9);
      while ( __strexd(v10 + 1, v9) );
      v11 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3036);
      do
        v12 = __ldrex(v11);
      while ( __strex(v12 + 1, v11) );
    }
    v13 = _10[0];
    if ( IopCancelSynchronousIrpsForThread(_10[0], a2) )
      v8 = 0;
    else
      v8 = -1073741275;
    *v4 = v8;
    v4[1] = 0;
    ObfDereferenceObject(v13);
  }
  return v8;
}
