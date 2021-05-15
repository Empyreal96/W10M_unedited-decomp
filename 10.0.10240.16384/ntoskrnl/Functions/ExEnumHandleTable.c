// ExEnumHandleTable 
 
int __fastcall ExEnumHandleTable(int a1, int (__fastcall *a2)(_DWORD, _DWORD, _DWORD, _DWORD), int a3, int *a4)
{
  unsigned int v7; // r5
  int v8; // r9
  _DWORD *v9; // r1
  int v10; // r4
  unsigned int v11; // r1
  int v12; // r4
  int v13; // r0
  _DWORD *v14; // r6
  __int16 v15; // r3
  int (__fastcall *v17)(_DWORD, _DWORD, _DWORD, _DWORD); // [sp+0h] [bp-28h] BYREF
  int (__fastcall *v18)(int, _DWORD *, _DWORD, int); // [sp+4h] [bp-24h]
  int *v19; // [sp+8h] [bp-20h]

  v17 = a2;
  v19 = a4;
  v18 = (int (__fastcall *)(int, _DWORD *, _DWORD, int))a2;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = 0;
  --*(_WORD *)(v7 + 308);
  v9 = 0;
  while ( 2 )
  {
    v13 = ExpGetNextHandleTableEntry(a1, v9, &v17);
    v14 = (_DWORD *)v13;
    if ( v13 )
    {
      do
      {
        while ( 1 )
        {
          __pld(v14);
          v10 = *v14;
          if ( (*v14 & 1) != 0 )
            break;
          if ( !v10 )
            goto LABEL_7;
          ExpBlockOnLockedHandleEntry(a1, (unsigned __int64 *)v14, *v14);
        }
        do
          v11 = __ldrex(v14);
        while ( v11 == v10 && __strex(v10 - 1, v14) );
        __dmb(0xBu);
      }
      while ( v11 != v10 );
      v12 = (int)v17;
      v13 = v18(a1, v14, v17, a3);
      v8 = v13;
      if ( !v13 )
      {
LABEL_7:
        v9 = v14;
        continue;
      }
      if ( a4 )
        *a4 = v12;
    }
    break;
  }
  v15 = *(_WORD *)(v7 + 308) + 1;
  *(_WORD *)(v7 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v7 + 100) != v7 + 100 && !*(_WORD *)(v7 + 310) )
    KiCheckForKernelApcDelivery(v13);
  return v8;
}
