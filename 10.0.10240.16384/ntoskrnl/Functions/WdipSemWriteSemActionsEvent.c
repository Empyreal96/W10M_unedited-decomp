// WdipSemWriteSemActionsEvent 
 
int __fastcall WdipSemWriteSemActionsEvent(int a1, int a2)
{
  unsigned int v3; // r6
  int v5; // r4
  unsigned int v6; // r3
  unsigned int v7; // r0
  int v8; // r9
  int v9; // r3
  int v10; // r8
  int v11; // r0
  _DWORD *v12; // lr
  int v13; // r2
  int v14; // r3
  int v15; // r4
  int v16; // r4
  char *v17; // r3
  unsigned int v18; // r3
  char *v19; // r5
  int v20; // t1
  int v22; // [sp+8h] [bp-A28h] BYREF
  char *v23; // [sp+Ch] [bp-A24h]
  char *v24; // [sp+10h] [bp-A20h]
  int v25; // [sp+14h] [bp-A1Ch]
  _DWORD *v26; // [sp+18h] [bp-A18h]
  int v27; // [sp+20h] [bp-A10h]
  int v28; // [sp+24h] [bp-A0Ch]
  int v29; // [sp+28h] [bp-A08h]
  int v30; // [sp+2Ch] [bp-A04h]
  int v31; // [sp+30h] [bp-A00h]
  int v32; // [sp+34h] [bp-9FCh]
  int v33; // [sp+38h] [bp-9F8h]
  int v34; // [sp+3Ch] [bp-9F4h]
  int *v35; // [sp+40h] [bp-9F0h]
  int v36; // [sp+44h] [bp-9ECh]
  int v37; // [sp+48h] [bp-9E8h]
  int v38; // [sp+4Ch] [bp-9E4h]
  int v39; // [sp+50h] [bp-9E0h]
  int v40; // [sp+54h] [bp-9DCh]
  int v41; // [sp+58h] [bp-9D8h]
  int v42; // [sp+5Ch] [bp-9D4h]
  char v43; // [sp+60h] [bp-9D0h] BYREF
  char v44[528]; // [sp+820h] [bp-210h] BYREF

  v3 = 0;
  v22 = 0;
  if ( !a1 || !a2 )
    return -1073741811;
  __dmb(0xBu);
  v6 = WdipContextLoggerId;
  do
    v7 = __ldrex((unsigned int *)&WdipContextLoggerId);
  while ( __strex(v6, (unsigned int *)&WdipContextLoggerId) );
  __dmb(0xBu);
  v5 = WdipSemGetLoggerDroppedEventCount(v7, &v22);
  if ( v5 >= 0 )
  {
    v8 = *(_DWORD *)(a2 + 24);
    v9 = *(_DWORD *)(v8 + 48);
    v27 = v8;
    v25 = v9 + 4;
    v28 = 0;
    v29 = 16;
    v30 = 0;
    v31 = v8 + 16;
    v32 = 0;
    v33 = 2;
    v34 = 0;
    v35 = &v22;
    v36 = 0;
    v37 = 4;
    v38 = 0;
    v39 = v8 + 48;
    v40 = 0;
    v41 = 4;
    v42 = 0;
    if ( *(_DWORD *)(v8 + 48) )
    {
      v23 = &v43;
      v24 = &v44[-a2];
      v10 = a2;
      while ( 1 )
      {
        v26 = *(_DWORD **)(v8 - a2 + v10 + 56);
        v11 = WdipSemFastAllocate(4, 40);
        if ( !v11 )
          break;
        v12 = v26;
        ++v3;
        v13 = v26[1];
        v14 = v26[2];
        v15 = v26[3];
        *(_DWORD *)v11 = *v26;
        *(_DWORD *)(v11 + 4) = v13;
        *(_DWORD *)(v11 + 8) = v14;
        *(_DWORD *)(v11 + 12) = v15;
        v16 = (int)v23;
        *(_BYTE *)(v11 + 16) = *((_BYTE *)v12 + 18);
        *(_DWORD *)(v11 + 24) = v12[6];
        *(_DWORD *)(v11 + 28) = v12[7];
        *(_DWORD *)(v11 + 32) = v12[9];
        *(_DWORD *)(v11 + 36) = *(_DWORD *)(v10 + 36);
        *(_QWORD *)(v16 + 4) = 0x2800000000i64;
        v17 = v24;
        *(_DWORD *)v16 = v11;
        *(_DWORD *)(v16 + 12) = 0;
        *(_DWORD *)&v17[v10] = v11;
        v18 = *(_DWORD *)(v8 + 48);
        v23 = (char *)(v16 + 16);
        v10 += 4;
        if ( v3 >= v18 )
          goto LABEL_11;
      }
      v5 = -1073741670;
    }
    else
    {
LABEL_11:
      v5 = WdipSemWriteEvent(WdipSemRegHandle, dword_61CB14, a1, a2 + 8);
    }
  }
  if ( v3 )
  {
    v19 = v44;
    do
    {
      v20 = *(_DWORD *)v19;
      v19 += 4;
      WdipSemFastFree(4, v20);
      --v3;
    }
    while ( v3 );
  }
  return v5;
}
