// PfSnLogStreamDelete 
 
int __fastcall PfSnLogStreamDelete(_DWORD *a1, _DWORD *a2, int a3, _DWORD *a4)
{
  int v6; // r4
  _DWORD *v7; // r2
  _DWORD *v8; // r1
  int v10[4]; // [sp+0h] [bp-10h] BYREF

  v10[0] = (int)a4;
  v6 = PfSnTraceGetLogEntry(a2, 5, v10);
  if ( v6 >= 0 )
  {
    v7 = (_DWORD *)v10[0];
    *(_DWORD *)v10[0] = 0;
    *v7 = 37;
    v7[1] = a1[2];
    v8 = (_DWORD *)(((unsigned int)v7 + 15) & 0xFFFFFFF8);
    *v8 = 0;
    *v8 = 323;
    v6 = 0;
    v8[1] = a1[6];
    v8[2] = a1[7];
    v8[4] &= 0xFFFFFFFC;
    v8[5] = a1[2];
  }
  else
  {
    PfSnFailProcessTrace((int)a2);
  }
  return v6;
}
