// IoWMIExecuteMethod 
 
int __fastcall IoWMIExecuteMethod(int a1, unsigned __int16 *a2, unsigned int a3, unsigned int a4, unsigned int *a5, int a6)
{
  unsigned int v8; // r2
  int v11; // r4
  unsigned int *v12; // r5
  unsigned int v13; // r4
  int v14; // r3
  unsigned int v15; // r9
  _WORD *v16; // r0
  int v17; // r3
  unsigned int v18; // r2
  unsigned int *v20; // [sp+10h] [bp-30h] BYREF
  unsigned int v21; // [sp+14h] [bp-2Ch] BYREF
  int v22; // [sp+18h] [bp-28h] BYREF
  unsigned int v23[9]; // [sp+1Ch] [bp-24h] BYREF

  v8 = *a5;
  v20 = 0;
  if ( a4 > v8 )
    v8 = a4;
  v11 = WmipAllocateSingleInstanceWnode(68, a2, v8, &v22, v23, &v21, &v20);
  v12 = v20;
  if ( v11 >= 0 )
  {
    v13 = v21;
    v20[11] = 0x8000;
    v12[4] = 0;
    *v12 = v13;
    v12[3] = 0;
    v14 = v22;
    v12[14] = a3;
    v15 = v23[0];
    v12[12] = v14;
    v12[15] = v15;
    v12[16] = a4;
    v16 = (_WORD *)((char *)v12 + v12[12]);
    *v16 = *a2;
    memmove((int)(v16 + 1), *((_DWORD *)a2 + 1), *a2);
    memmove((int)v12 + v12[15], a6, a4);
    v23[0] = *v12;
    v11 = WmipQuerySetExecuteSI(a1, 0, 0, 9, (int)v12, v13, v23);
    if ( v11 >= 0 )
    {
      if ( (v12[11] & 0x20) != 0 )
      {
        v17 = v12[12] - v15 + 7;
      }
      else
      {
        v18 = v12[16];
        if ( *a5 >= v18 )
        {
          *a5 = v18;
          memmove(a6, (int)v12 + v12[15], v12[16]);
          goto LABEL_11;
        }
        v17 = v18 + 7;
      }
      v11 = -1073741789;
      *a5 = v17 & 0xFFFFFFF8;
    }
  }
LABEL_11:
  if ( v12 )
    ExFreePoolWithTag((unsigned int)v12);
  return v11;
}
