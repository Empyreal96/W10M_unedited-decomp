// CmpLogHiveRundownEvent 
 
int __fastcall CmpLogHiveRundownEvent(int a1, int a2)
{
  int v3; // r0
  int v4; // r4
  int v6; // r1
  int v7; // r3
  int *v8; // r3
  int v9; // r1
  int v10; // r2
  int *v11; // r3
  int *v12; // r3
  __int16 v14[4]; // [sp+8h] [bp-90h] BYREF
  int var88[35]; // [sp+10h] [bp-88h] BYREF
  int vars8[2]; // [sp+A0h] [bp+8h] BYREF

  vars8[1] = a2;
  vars8[0] = a1;
  v14[0] = 0;
  v3 = *(_DWORD *)(a1 + 1980);
  v4 = *(_DWORD *)(vars8[0] + 1988);
  var88[0] = vars8[0] + 1944;
  var88[1] = 0;
  var88[2] = 8;
  var88[3] = 0;
  var88[4] = (int)vars8;
  var88[5] = 0;
  var88[6] = 4;
  var88[7] = 0;
  var88[8] = vars8[0] + 3852;
  var88[9] = 0;
  var88[10] = 4;
  v6 = 3;
  var88[11] = 0;
  if ( v3 )
  {
    v7 = *(unsigned __int16 *)(a1 + 1976);
    var88[13] = 0;
    var88[14] = v7;
    var88[15] = 0;
    var88[12] = v3;
    v6 = 4;
  }
  v8 = &var88[4 * v6];
  v9 = v6 + 1;
  *v8 = (int)v14;
  v8[1] = 0;
  v8[2] = 2;
  v8[3] = 0;
  if ( v4 )
  {
    v10 = *(unsigned __int16 *)(a1 + 1984);
    v11 = &var88[4 * v9];
    *v11 = v4;
    v11[1] = 0;
    v11[2] = v10;
    v11[3] = 0;
    ++v9;
  }
  v12 = &var88[4 * v9];
  *v12 = (int)v14;
  v12[1] = 0;
  v12[2] = 2;
  v12[3] = 0;
  return EtwpLogKernelEvent(var88, a2, v9 + 1, 2343, 4200450);
}
