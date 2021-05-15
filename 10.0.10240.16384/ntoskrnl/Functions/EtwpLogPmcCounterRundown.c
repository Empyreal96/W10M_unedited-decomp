// EtwpLogPmcCounterRundown 
 
int __fastcall EtwpLogPmcCounterRundown(int result, int a2)
{
  int *v2; // r5
  int v3; // r7
  int v4; // r3
  unsigned int v5; // r2
  unsigned int v6; // r9
  int v7; // r6
  int v8; // t1
  int (__cdecl *v9)(); // r4
  unsigned __int16 *v10; // r4
  unsigned int v11; // r0
  int *v12; // r2
  unsigned int v13; // [sp+8h] [bp-C0h] BYREF
  int v14; // [sp+Ch] [bp-BCh]
  int v15; // [sp+10h] [bp-B8h]
  int v16[44]; // [sp+18h] [bp-B0h] BYREF

  v2 = *(int **)(result + 628);
  v3 = a2;
  v14 = a2;
  v4 = v2[7];
  __dmb(0xBu);
  if ( v4 )
  {
    v5 = v2[7];
    __dmb(0xBu);
    v16[0] = (int)&v13;
    v13 = v5;
    v16[1] = 0;
    v16[2] = 4;
    v16[3] = 0;
    v6 = 0;
    if ( v5 )
    {
      v7 = 0;
      do
      {
        v15 = 0;
        v8 = *v2++;
        v9 = (int (__cdecl *)())off_617B54;
        v16[v7 + 20] = v8;
        if ( v9() < 0 )
          v10 = L"Unknown";
        else
          v10 = (unsigned __int16 *)v16[v7 + 23];
        v11 = wcslen(v10);
        v12 = &v16[v7 + 4];
        *v12 = (int)v10;
        v12[1] = 0;
        v12[2] = 2 * (v11 + 1);
        v12[3] = 0;
        v5 = v13;
        ++v6;
        v7 += 4;
      }
      while ( v6 < v13 );
      v3 = v14;
    }
    result = EtwpLogKernelEvent(v16, v3, v5 + 1, 3888, 4200450);
  }
  return result;
}
