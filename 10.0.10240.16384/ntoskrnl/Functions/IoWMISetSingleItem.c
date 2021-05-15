// IoWMISetSingleItem 
 
int __fastcall IoWMISetSingleItem(int a1, unsigned __int16 *a2, unsigned int a3, unsigned int a4, unsigned int a5, int a6)
{
  int v9; // r4
  unsigned int v10; // r5
  unsigned int *v11; // r6
  int v12; // r3
  unsigned int v13; // r3
  unsigned int *v15; // [sp+10h] [bp-30h] BYREF
  unsigned int v16; // [sp+14h] [bp-2Ch] BYREF
  int v17; // [sp+18h] [bp-28h] BYREF
  unsigned int v18; // [sp+1Ch] [bp-24h] BYREF
  int v19; // [sp+20h] [bp-20h]

  v19 = a1;
  v9 = WmipAllocateSingleInstanceWnode(68, a2, a5, &v17, &v18, &v16, &v15);
  if ( v9 >= 0 )
  {
    v11 = v15;
    v10 = v16;
    v15[11] = 4;
    v11[4] = 0;
    *v11 = v10;
    v11[2] = a4;
    v11[3] = 0;
    v12 = v17;
    v11[14] = a3;
    v11[12] = v12;
    *(_WORD *)((char *)v11 + v12) = *a2;
    memmove((int)v11 + v12 + 2, *((_DWORD *)a2 + 1), *a2);
    v13 = v18;
    v11[15] = v18;
    v11[16] = a5;
    memmove((int)v11 + v13, a6, a5);
    v18 = *v11;
    v9 = WmipQuerySetExecuteSI(v19, 0, 0, 3, (int)v11, v10, &v18);
    ExFreePoolWithTag((unsigned int)v11);
  }
  return v9;
}
