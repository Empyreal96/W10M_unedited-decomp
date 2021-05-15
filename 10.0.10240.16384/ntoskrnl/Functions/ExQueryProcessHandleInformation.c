// ExQueryProcessHandleInformation 
 
int __fastcall ExQueryProcessHandleInformation(int a1, unsigned int *a2, int a3, int *a4)
{
  _DWORD *v5; // r6
  unsigned int v6; // r9
  int v7; // r5
  int v8; // r8
  _DWORD *i; // r1
  _DWORD *v10; // r0
  _DWORD *v11; // r4
  int v12; // r0
  unsigned int v13; // r1
  unsigned int v14; // r1
  int v17; // [sp+0h] [bp-58h] BYREF
  unsigned int *v18; // [sp+4h] [bp-54h]
  unsigned int v19; // [sp+8h] [bp-50h]
  _DWORD *v20; // [sp+Ch] [bp-4Ch]
  _DWORD *v21; // [sp+10h] [bp-48h]
  int *v22; // [sp+14h] [bp-44h]
  unsigned int v23; // [sp+18h] [bp-40h]
  unsigned int v24; // [sp+1Ch] [bp-3Ch]
  int v25; // [sp+20h] [bp-38h]
  _DWORD _28[18]; // [sp+28h] [bp-30h] BYREF

  _28[16] = a3;
  v22 = a4;
  _28[17] = a4;
  v18 = a2;
  _28[15] = a2;
  _28[14] = a1;
  v5 = a2 + 2;
  v20 = a2 + 2;
  v19 = (a3 - 8) / 0x1Cu;
  v23 = v19;
  v6 = 0;
  v7 = 8;
  v8 = 0;
  for ( i = 0; ; i = v11 )
  {
    v10 = (_DWORD *)ExpGetNextHandleTableEntry(a1, i, &v17);
    v11 = v10;
    v21 = v10;
    if ( !v10 )
      break;
    if ( v6 >= v19 )
    {
      if ( (v17 & 0x7FC) != 0 && *v10 )
      {
        v7 += 28;
        v8 = -1073741820;
      }
    }
    else
    {
      do
      {
        while ( 1 )
        {
          __pld(v11);
          v12 = *v11;
          if ( (*v11 & 1) != 0 )
            break;
          if ( !v12 )
            goto LABEL_21;
          ExpBlockOnLockedHandleEntry(a1, (unsigned __int64 *)v11, *v11);
        }
        do
          v13 = __ldrex(v11);
        while ( v13 == v12 && __strex(v12 - 1, v11) );
        __dmb(0xBu);
      }
      while ( v13 != v12 );
      ObQueryHandleEntryInformation(v11, _28);
      __dmb(0xBu);
      do
        v14 = __ldrex(v11);
      while ( __strex(v14 + 1, v11) );
      __dmb(0xBu);
      __dmb(0xFu);
      if ( *(_DWORD *)(a1 + 32) )
        ExfUnblockPushLock(a1 + 32, 0);
      v7 += 28;
      v25 = v7;
      v24 = ++v6;
      *v5 = v17;
      v5[1] = _28[0];
      v5[2] = _28[1];
      v5[3] = _28[2];
      v5[4] = _28[3];
      v5[5] = _28[4];
      v5[6] = 0;
      *v18 = v6;
      v5 += 7;
      v20 = v5;
    }
LABEL_21:
    ;
  }
  if ( v22 )
    *v22 = v7;
  return v8;
}
