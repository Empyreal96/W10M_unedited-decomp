// IoWMISetSingleInstance 
 
int __fastcall IoWMISetSingleInstance(int a1, unsigned __int16 *a2, unsigned int a3, unsigned int a4, int a5)
{
  int v9; // r4
  unsigned int v10; // r5
  unsigned int *v11; // r6
  int v12; // r3
  unsigned int v13; // r3
  unsigned int *v15; // [sp+10h] [bp-30h] BYREF
  unsigned int v16; // [sp+14h] [bp-2Ch] BYREF
  int v17; // [sp+18h] [bp-28h] BYREF
  unsigned int v18[9]; // [sp+1Ch] [bp-24h] BYREF

  v9 = WmipAllocateSingleInstanceWnode(64, a2, a4, &v17, v18, &v16, &v15);
  if ( v9 >= 0 )
  {
    v11 = v15;
    v10 = v16;
    v15[11] = 2;
    v11[4] = 0;
    *v11 = v10;
    v11[2] = a3;
    v11[3] = 0;
    v12 = v17;
    v11[12] = v17;
    *(_WORD *)((char *)v11 + v12) = *a2;
    memmove((int)v11 + v12 + 2, *((_DWORD *)a2 + 1), *a2);
    v13 = v18[0];
    v11[14] = v18[0];
    v11[15] = a4;
    memmove((int)v11 + v13, a5, a4);
    v18[0] = *v11;
    v9 = WmipQuerySetExecuteSI(a1, 0, 0, 2, (int)v11, v10, v18);
    ExFreePoolWithTag((unsigned int)v11);
  }
  return v9;
}
