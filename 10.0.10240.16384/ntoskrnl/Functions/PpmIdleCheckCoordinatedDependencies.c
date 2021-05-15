// PpmIdleCheckCoordinatedDependencies 
 
int __fastcall PpmIdleCheckCoordinatedDependencies(int a1, int a2, unsigned int a3, int a4, int a5, int a6, unsigned int a7, unsigned int *a8, int a9, int a10, int a11)
{
  unsigned int v11; // r5
  int v15; // r0
  unsigned int v16; // r4
  unsigned int v17; // t1
  __int64 v18; // r0
  _DWORD *v19; // r4
  int v21; // [sp+18h] [bp-20h]

  v11 = 0;
  v21 = a2;
  if ( a7 )
  {
    v15 = a11;
    while ( 1 )
    {
      v17 = *a8;
      a8 += 3;
      v16 = v17;
      if ( v17 == -1 )
      {
        LODWORD(v18) = PpmIdleCheckCoordinatedDependency(a1, a2, a3);
      }
      else if ( v16 == *(_DWORD *)(a1 + 20) )
      {
        LODWORD(v18) = PpmIdleSelectCoordinatedProcessorDependency(a1, a2, a3);
      }
      else
      {
        v19 = v16 >= KeNumberProcessors_0 ? 0 : *(&KiProcessorBlock + v16);
        if ( PpmTestAndLockProcessor(v19, v15, a8 - 2) >= 0 )
          LODWORD(v18) = *(_BYTE *)(PpmPlatformStates + 12) && *(_DWORD *)(v19[736] + (v19[747] << 6) + 272) > a3 ? -2147483646 : 0;
        else
          LODWORD(v18) = -2147483643;
        HIDWORD(v18) = 0;
      }
      if ( v18 )
        break;
      ++v11;
      a2 = v21;
      v15 = a11;
      if ( v11 >= a7 )
        goto LABEL_19;
    }
  }
  else
  {
LABEL_19:
    LODWORD(v18) = 0;
  }
  return v18;
}
