// EtwpRealtimeDeliverBuffer 
 
int __fastcall EtwpRealtimeDeliverBuffer(_DWORD *a1, int a2)
{
  int *v3; // r4
  int *v6; // r8
  int *v7; // r10
  int *v8; // r7
  char v9; // r3
  __int16 v10; // r9
  int v11; // r0
  int v12; // r2
  int v13; // [sp+0h] [bp-28h]

  v3 = 0;
  v13 = 0;
  if ( a1[88] )
    return sub_809EA4();
  v6 = (int *)a1[64];
  if ( v6 == a1 + 64 )
    return -1073741823;
  v7 = a1 + 64;
  do
  {
    v8 = v6;
    v9 = *((_BYTE *)v6 + 50);
    v6 = (int *)*v6;
    v10 = *(_WORD *)(a2 + 52);
    if ( (v9 & 2) != 0 )
      *(_WORD *)(a2 + 52) = v10 | 4;
    v11 = EtwpRealtimeInjectEtwBuffer(a1, v8, a2);
    *(_WORD *)(a2 + 52) = v10;
    if ( v11 < 0 )
    {
      if ( v11 == -1073741764 )
      {
        v8[4] = (int)v3;
        v3 = v8;
      }
      else
      {
LABEL_18:
        EtwpDisassociateConsumer(a1, v8);
      }
LABEL_19:
      v12 = v13;
      continue;
    }
    if ( (*((_BYTE *)v8 + 50) & 2) != 0 )
      *((_BYTE *)v8 + 50) &= 0xFDu;
    v12 = 1;
    v13 = 1;
    if ( (*((_BYTE *)v8 + 50) & 1) != 0 )
    {
      if ( (*(_WORD *)(a2 + 52) & 1) != 0 )
        goto LABEL_18;
      goto LABEL_19;
    }
  }
  while ( v6 != v7 );
  if ( !v12 )
    return -1073741823;
  if ( *(_WORD *)(a2 + 54) != 6 )
    ++a1[46];
  while ( v3 )
  {
    *((_BYTE *)v3 + 50) |= 2u;
    ++v3[10];
    v3 = (int *)v3[4];
  }
  return 0;
}
