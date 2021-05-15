// WmipDereferenceEvent 
 
unsigned int *__fastcall WmipDereferenceEvent(int a1)
{
  unsigned int *v2; // r7
  unsigned int v3; // r2
  unsigned int v4; // r9
  int v5; // r3
  unsigned int v6; // r3
  unsigned int v7; // r2
  unsigned int v8; // r10
  unsigned int *v9; // r0
  unsigned int v10; // r2
  unsigned int v11; // r3
  unsigned int v12; // r4
  int v13; // r4
  unsigned int v14; // r5
  int v16; // [sp+8h] [bp-40h]
  unsigned int v17; // [sp+Ch] [bp-3Ch]
  int v18; // [sp+10h] [bp-38h]
  _DWORD *v19; // [sp+14h] [bp-34h]
  int v20; // [sp+18h] [bp-30h]
  unsigned int v21; // [sp+1Ch] [bp-2Ch]
  int v22[10]; // [sp+20h] [bp-28h] BYREF

  v2 = 0;
  v17 = 0;
  v19 = (_DWORD *)WmipFindDSByProviderId(*(_DWORD *)(a1 + 4));
  if ( v19 )
  {
    v3 = 64;
    v20 = *(_DWORD *)(a1 + 44) & 0x80;
    if ( v20 )
    {
      v4 = 0;
      v5 = 0;
    }
    else
    {
      v4 = *(unsigned __int16 *)(a1 + 68) + 2;
      v5 = 64;
      v3 = *(unsigned __int16 *)(a1 + 68) + 66;
    }
    v16 = v5;
    v6 = v3 + 7;
    if ( v3 + 7 >= v3 )
    {
      v7 = *(_DWORD *)(a1 + 64);
      v21 = v6 & 0xFFFFFFF8;
      if ( v7 <= -1 - (v6 & 0xFFFFFFF8) )
      {
        v18 = 0;
        v8 = v7 + (v6 & 0xFFFFFFF8);
        while ( 1 )
        {
          v9 = (unsigned int *)ExAllocatePoolWithTag(512, v8, 1885957463);
          v2 = v9;
          if ( !v9 )
            break;
          memset(v9, 0, v8);
          *v2 = v8;
          v2[1] = *(_DWORD *)(a1 + 4);
          v10 = *(_DWORD *)(a1 + 52);
          v11 = *(_DWORD *)(a1 + 56);
          v12 = *(_DWORD *)(a1 + 60);
          v2[6] = *(_DWORD *)(a1 + 48);
          v2[7] = v10;
          v2[8] = v11;
          v2[9] = v12;
          v2[2] = *(_DWORD *)(a1 + 8);
          v2[11] = v20 | 2;
          v2[14] = v21;
          if ( v20 )
          {
            v2[13] = *(_DWORD *)(a1 + 68);
          }
          else
          {
            v4 -= 2;
            v2[12] = v16;
            *(_WORD *)((char *)v2 + v16) = v4;
            memmove((int)v2 + v16 + 2, a1 + 70, v4);
          }
          v13 = WmipSendWmiIrp(1, v19[7], (int)(v2 + 6), v8, (int)v2, v22);
          if ( v13 < 0 )
          {
            v14 = v17;
          }
          else
          {
            if ( (v2[11] & 0x20) == 0 )
            {
              v2[11] |= *(_DWORD *)(a1 + 44) & 0xFF000008 | 8;
              break;
            }
            v14 = v2[12];
            v17 = v14;
          }
          ExFreePoolWithTag((unsigned int)v2);
          v2 = 0;
          if ( v13 >= 0 && v14 > v8 )
          {
            v8 = v14;
            if ( (unsigned int)++v18 < 2 )
              continue;
          }
          break;
        }
      }
    }
    WmipUnreferenceEntry((int *)&WmipDSChunkInfo, v19);
  }
  return v2;
}
