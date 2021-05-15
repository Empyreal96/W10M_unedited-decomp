// RtlFindMessage 
 
int __fastcall RtlFindMessage(int a1, int a2, int a3, unsigned int a4, _DWORD *a5)
{
  int result; // r0
  int *v8; // [sp+8h] [bp-28h] BYREF
  int v9; // [sp+Ch] [bp-24h] BYREF
  _DWORD v10[8]; // [sp+10h] [bp-20h] BYREF

  v10[2] = a3;
  v10[3] = a4;
  v10[0] = a2;
  v10[1] = 1;
  result = LdrpSearchResourceSection_U(a1, v10, 4, 64, &v9);
  if ( result >= 0 )
  {
    result = LdrpAccessResourceData(a1, v9, &v8, 0);
    if ( result >= 0 )
      result = RtlFindMessageInTable(v8, a4, a5);
  }
  return result;
}
