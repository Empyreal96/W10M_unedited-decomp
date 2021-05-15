// BiDoesHiveKeyExist 
 
int __fastcall BiDoesHiveKeyExist(unsigned __int16 *a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v6; // r6
  int v7; // r0
  int v8; // r5
  int v9; // r0
  int v11; // [sp+0h] [bp-20h] BYREF
  int v12[7]; // [sp+4h] [bp-1Ch] BYREF

  v12[1] = a4;
  v4 = 0;
  v11 = 0;
  v12[0] = 0;
  v6 = 0;
  if ( !wcschr(a1, 92) )
  {
    v7 = BiOpenKeyNonBcd(0, L"\\Registry\\Machine", 131097, v12);
    v8 = v12[0];
    if ( v7 >= 0 )
    {
      v9 = BiOpenKeyNonBcd(v12[0], a1, 131097, &v11);
      v4 = v11;
      if ( v9 >= 0 )
        v6 = 1;
    }
    if ( v8 )
      ZwClose();
    if ( v4 )
      ZwClose();
  }
  return v6;
}
