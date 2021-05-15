// SmStoreResize 
 
int __fastcall SmStoreResize(int a1, int a2, int a3, int *a4, int a5)
{
  int result; // r0
  char v7[8]; // [sp+8h] [bp-30h] BYREF
  int v8[2]; // [sp+10h] [bp-28h] BYREF
  int v9; // [sp+18h] [bp-20h]
  int v10; // [sp+1Ch] [bp-1Ch]
  int v11; // [sp+20h] [bp-18h]
  int v12; // [sp+24h] [bp-14h]
  int *v13; // [sp+28h] [bp-10h]
  int v14; // [sp+2Ch] [bp-Ch]

  v11 = 1;
  v8[1] = a2;
  v12 = 17;
  v13 = v8;
  v14 = 16;
  v8[0] = ((a5 != 0) << 8) | 6;
  v9 = *a4;
  v10 = a3;
  if ( !a1 )
  {
    result = SmStorePhysicalRequestIssue(dword_636C98, 2261452, v8, 16, 16, v7);
LABEL_5:
    *a4 = v9;
    return result;
  }
  if ( a1 == 1 )
  {
    result = ZwSetSystemInformation();
    goto LABEL_5;
  }
  return -1073741811;
}
