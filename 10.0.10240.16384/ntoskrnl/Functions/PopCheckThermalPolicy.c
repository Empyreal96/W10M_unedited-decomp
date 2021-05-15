// PopCheckThermalPolicy 
 
unsigned int __fastcall PopCheckThermalPolicy(int a1, int a2, unsigned int a3, unsigned int a4, _BYTE *a5, _DWORD *a6)
{
  unsigned int v6; // r1
  unsigned int v7; // r7
  unsigned int v10; // r2
  unsigned int v11; // r2
  unsigned int result; // r0
  unsigned int v13; // r2
  unsigned int v14; // r3
  unsigned int v15; // r8
  unsigned int v16; // r3
  int v17; // r1
  int v18; // r2
  int v19; // r7
  int v20; // r10
  int v21; // r5
  unsigned int v22; // r2
  unsigned int v23; // r3
  unsigned int v24; // [sp+8h] [bp-28h]

  v6 = *(_DWORD *)(a1 + 188);
  v7 = a4;
  v24 = a3;
  if ( v6 && *(_DWORD *)(a1 + 176) >= v6 )
    return sub_814E94();
  *(_BYTE *)(a1 + 262) = 0;
  v10 = *(_DWORD *)(a1 + 236);
  if ( v10 && *(_DWORD *)(a1 + 176) >= v10 )
  {
    if ( (PoDebug & 0x21) != 0 )
      DbgPrint(
        "Thermal Zone %p: Above critical S4 temperature (_TMP 0x%x, _HOT 0x%x). Hibernate initiated\n",
        (const void *)a1,
        *(_DWORD *)(a1 + 176),
        *(_DWORD *)(a1 + 236));
    *(_BYTE *)(a1 + 261) = 1;
  }
  else
  {
    *(_BYTE *)(a1 + 261) = 0;
  }
  v11 = *(_DWORD *)(a1 + 184);
  if ( v11 )
  {
    if ( *(_DWORD *)(a1 + 176) < v11 )
    {
      if ( *(_BYTE *)(a1 + 263) )
        *(_BYTE *)(a1 + 263) = 0;
    }
    else if ( !*(_BYTE *)(a1 + 263) )
    {
      *(_BYTE *)(a1 + 263) = 1;
      if ( (PoDebug & 0x21) != 0 )
        DbgPrint(
          "Thermal Zone %p: Above Thermal Standby temperature (_TMP 0x%x, _CR3 0x%x). Thermal Standby initiated\n",
          (const void *)a1,
          *(_DWORD *)(a1 + 176),
          *(_DWORD *)(a1 + 184));
    }
  }
  result = *(unsigned __int8 *)(a1 + 192);
  v13 = 0;
  if ( *(_BYTE *)(a1 + 192) )
  {
    v17 = a1;
    do
    {
      if ( *(_DWORD *)(a1 + 176) >= *(_DWORD *)(v17 + 196) )
        break;
      ++v13;
      v17 += 4;
    }
    while ( v13 < result );
  }
  v14 = *(_DWORD *)(a1 + 64);
  *(_DWORD *)(a1 + 272) = v13;
  if ( __PAIR64__(v7, a3) - __PAIR64__(*(_DWORD *)(a1 + 68), v14) < *(unsigned int *)(a1 + 72) )
  {
    *a6 = 0;
    *a5 = *(_BYTE *)(a1 + 33) & 1;
  }
  else
  {
    v15 = *(_DWORD *)(a1 + 176);
    if ( *(_DWORD *)(a1 + 48) == 100 && ((v16 = *(_DWORD *)(a1 + 180), v15 < v16) || !v16) )
    {
      *(_DWORD *)(a1 + 264) = 0;
      *a6 = 0;
      *a5 = 0;
    }
    else
    {
      if ( (*(_BYTE *)(a1 + 33) & 1) == 0 )
      {
        v18 = *(_DWORD *)(a1 + 172);
        *(_DWORD *)(a1 + 64) = 0;
        *(_DWORD *)(a1 + 68) = 0;
        *(_DWORD *)(a1 + 72) = 10000 * v18;
        *(_DWORD *)(a1 + 76) = *(_DWORD *)(a1 + 180);
      }
      v19 = v15 - *(_DWORD *)(a1 + 76);
      v20 = v15 - *(_DWORD *)(a1 + 180);
      v21 = *(_DWORD *)(a1 + 44);
      *a6 = *(_DWORD *)(a1 + 164) * v19 + *(_DWORD *)(a1 + 168) * v20;
      if ( (PoDebug & 0x20) != 0 )
        result = DbgPrint(
                   "Thermal Zone %p: LastTemp=%u CurrentTemp=%u (LastTempChange = %d)\n",
                   (const void *)a1,
                   *(_DWORD *)(a1 + 76),
                   v15,
                   v19);
      if ( (PoDebug & 0x20) != 0 )
        result = DbgPrint(
                   "Thermal Zone %p: PassiveTripPoint=%u TempChangeNeeded=%d\n",
                   (const void *)a1,
                   *(_DWORD *)(a1 + 180),
                   v20);
      if ( v19 && (*a6 ^ v19) < 0 )
      {
        if ( (PoDebug & 0x20) != 0 )
          result = DbgPrint(
                     "ERROR: Thermal Zone %p: TempDelta (%d) & ThrottleDelta (%d.%d) not moving in the same direction\n",
                     (const void *)a1,
                     v19,
                     *a6 / 10,
                     *a6 % 10);
      }
      else
      {
        if ( (PoDebug & 0x20) != 0 )
          result = DbgPrint(
                     "Thermal Zone %p: Subtracting ThrottleDelta %d.%d from CurrentThrottle %d.%d\n",
                     (const void *)a1,
                     *a6 / 10,
                     *a6 % 10,
                     v21 / 10,
                     v21 % 10);
        v21 -= *a6;
      }
      if ( v21 > 1000 )
        v21 = 1000;
      if ( v21 < 0 )
        v21 = 0;
      if ( v21 < 10 * *(_DWORD *)(a1 + 240) )
        v21 = 10 * *(_DWORD *)(a1 + 240);
      *(_DWORD *)(a1 + 44) = v21;
      v22 = (v21 + 5) / 10;
      v23 = *(_DWORD *)(a1 + 244);
      *(_DWORD *)(a1 + 268) = v22;
      *(_BYTE *)(a1 + 276) = v22 < v23;
      *(_DWORD *)(a1 + 76) = v15;
      *a6 = 0;
      *(_DWORD *)(a1 + 64) = v24;
      *(_DWORD *)(a1 + 264) = 1;
      *(_DWORD *)(a1 + 68) = a4;
      *a5 = 1;
    }
  }
  return result;
}
