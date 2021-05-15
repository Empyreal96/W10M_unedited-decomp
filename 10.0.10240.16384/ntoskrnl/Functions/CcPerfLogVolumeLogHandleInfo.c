// CcPerfLogVolumeLogHandleInfo 
 
int *__fastcall CcPerfLogVolumeLogHandleInfo(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r3
  int v10; // [sp+8h] [bp-50h] BYREF
  int v11; // [sp+Ch] [bp-4Ch]
  int v12; // [sp+10h] [bp-48h]
  int v13; // [sp+14h] [bp-44h]
  int v14; // [sp+18h] [bp-40h]
  int v15; // [sp+20h] [bp-38h]
  int v16; // [sp+24h] [bp-34h]
  int v17[12]; // [sp+28h] [bp-30h] BYREF

  v17[8] = a1;
  v17[9] = a2;
  v17[10] = a3;
  v17[11] = a4;
  v10 = a1;
  v12 = a3;
  v13 = a7;
  v14 = a8;
  v15 = a5;
  v16 = a6;
  v8 = 0;
  v11 = 0;
  if ( (a2 & 1) != 0 )
  {
    v8 = 1;
    v11 = 1;
  }
  if ( (a2 & 2) != 0 )
  {
    v8 |= 2u;
    v11 = v8;
  }
  if ( (a2 & 4) != 0 )
  {
    v8 |= 4u;
    v11 = v8;
  }
  if ( (a2 & 0x10) != 0 )
  {
    v8 |= 0x10u;
    v11 = v8;
  }
  if ( (a2 & 8) != 0 )
    v11 = v8 | 8;
  v17[0] = (int)&v10;
  v17[1] = 0;
  v17[2] = 32;
  v17[3] = 0;
  return EtwTraceKernelEvent(v17, 1, 0x80020000, 5645, 4200706);
}
