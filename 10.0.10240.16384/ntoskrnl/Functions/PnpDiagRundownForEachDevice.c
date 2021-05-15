// PnpDiagRundownForEachDevice 
 
int __fastcall PnpDiagRundownForEachDevice(int a1)
{
  unsigned int *v1; // r5
  unsigned int v3; // r7
  _DWORD *v4; // r4
  unsigned int v5; // r8
  unsigned __int8 *v6; // r6
  unsigned int v7; // r2
  int v8; // r3
  unsigned int v10; // [sp+8h] [bp-70h] BYREF
  int v11[26]; // [sp+10h] [bp-68h] BYREF

  v1 = *(unsigned int **)(a1 + 288);
  if ( v1 )
  {
    v3 = 0;
    if ( *v1 )
    {
      v4 = v1 + 1;
      do
      {
        v5 = 0;
        if ( v4[3] )
        {
          v6 = (unsigned __int8 *)(v4 + 4);
          do
          {
            if ( *v6 == 132 )
            {
              v7 = *(unsigned __int16 *)(a1 + 20);
              v11[1] = *((_DWORD *)v6 + 3);
              v8 = *((_DWORD *)v6 + 2);
              v11[16] = v7;
              v11[0] = v8;
              v11[2] = a1 + 16;
              v11[3] = 0;
              v11[4] = 4;
              v11[5] = 0;
              v11[6] = (int)v11;
              v11[7] = 0;
              v11[8] = 8;
              v11[9] = 0;
              v10 = v7 >> 1;
              v11[10] = (int)&v10;
              v11[11] = 0;
              v11[12] = 4;
              v11[13] = 0;
              v11[14] = *(_DWORD *)(a1 + 24);
              v11[15] = 0;
              v11[17] = 0;
              EtwWrite(PnpRundownEtwHandle, dword_649E8C, (int)KMPnPRundownEvt_SleepStudy_ConnectionResource, 0);
            }
            ++v5;
            v6 += 16;
          }
          while ( v5 < v4[3] );
        }
        ++v3;
        v4 += 8;
      }
      while ( v3 < *v1 );
    }
  }
  return 0;
}
