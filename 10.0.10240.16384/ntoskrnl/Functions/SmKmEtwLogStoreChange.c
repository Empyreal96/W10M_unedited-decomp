// SmKmEtwLogStoreChange 
 
int __fastcall SmKmEtwLogStoreChange(int *a1, int a2, int *a3)
{
  _DWORD *v6; // r4
  int v7; // r1
  int *v8; // r2
  int **v9; // r3
  int v10; // r1
  int v12[6]; // [sp+28h] [bp-1B0h] BYREF
  int v13; // [sp+40h] [bp-198h] BYREF
  char v14[72]; // [sp+44h] [bp-194h] BYREF
  _DWORD v15[4]; // [sp+90h] [bp-148h] BYREF
  char v16[288]; // [sp+A0h] [bp-138h] BYREF

  v15[0] = 0;
  v15[1] = 0;
  v15[2] = 0;
  v15[3] = 0;
  memset(v16, 0, sizeof(v16));
  v13 = 0;
  memset(v14, 0, sizeof(v14));
  memset(v12, 0, sizeof(v12));
  v12[3] = 19;
  v12[1] = (int)&v13;
  v12[5] = 76;
  v6 = v15;
  v12[0] = (int)v15;
  if ( a3 == SmEventStoreDelete )
  {
    v7 = v12[2];
    v8 = (int *)((char *)&v13 + v12[4]);
    *v8 = a2;
    v9 = (int **)&v15[4 * v7];
    *v9 = v8;
    v9[1] = 0;
    v9[2] = (int *)4;
    v9[3] = 0;
    v10 = v7 + 1;
  }
  else
  {
    SMKM_STORE<SM_TRAITS>::SmStEtwFillStoreEvent(a2, v12);
    v10 = v12[2];
    v6 = (_DWORD *)v12[0];
  }
  return EtwWriteEx(*a1, a1[1], (int)a3, (int)v9, 0, 0, 0, 0, 0, v10, (int)v6);
}
