// CmpCreatePredefined 
 
int __fastcall CmpCreatePredefined(int a1, unsigned __int16 *a2, int a3)
{
  int result; // r0
  int v7; // [sp+10h] [bp-88h] BYREF
  char v8[4]; // [sp+14h] [bp-84h] BYREF
  char v9[8]; // [sp+18h] [bp-80h] BYREF
  _DWORD v10[6]; // [sp+20h] [bp-78h] BYREF
  int v11; // [sp+38h] [bp-60h] BYREF
  int v12[19]; // [sp+3Ch] [bp-5Ch] BYREF

  memset(v12, 0, sizeof(v12));
  v12[4] = 16777217;
  v11 = 33;
  v12[9] = a3;
  RtlInitUnicodeString((unsigned int)v9, a2);
  v10[0] = 24;
  v10[1] = a1;
  v10[3] = 576;
  v10[2] = v9;
  v10[4] = 0;
  v10[5] = 0;
  result = ObOpenObjectByName((int)v10, (int)CmKeyObjectType, 0, 0, 131097, (int)&v11, &v7);
  if ( result >= 0 )
  {
    ObReferenceObjectByHandle(v7, 0, (int)CmKeyObjectType, 0, (int)v8, 0);
    result = ZwClose();
  }
  return result;
}
