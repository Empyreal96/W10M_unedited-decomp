// RtlGetSetBootStatusData 
 
int __fastcall RtlGetSetBootStatusData(int a1, int a2, int a3, int a4, unsigned int a5, int a6)
{
  int result; // r0
  unsigned int v9; // r1
  unsigned int v10; // [sp+28h] [bp-90h]
  int v11[34]; // [sp+30h] [bp-88h] BYREF

  v11[0] = 0;
  v11[1] = 4;
  v11[2] = 4;
  v11[3] = 4;
  v11[4] = 8;
  v11[5] = 1;
  v11[6] = 9;
  v11[7] = 1;
  v11[8] = 10;
  v11[9] = 1;
  v11[10] = 11;
  v11[11] = 1;
  v11[12] = 12;
  v11[13] = 1;
  v11[14] = 16;
  v11[15] = 32;
  v11[16] = 48;
  v11[17] = 1;
  v11[18] = 49;
  v11[19] = 1;
  v11[20] = 52;
  v11[21] = 4;
  v11[22] = 56;
  v11[23] = 4;
  v11[24] = 60;
  v11[25] = 4;
  result = ZwReadFile();
  if ( result >= 0 )
  {
    if ( a3 < 0 || (unsigned int)a3 >= 0xD )
    {
      result = -1073741811;
    }
    else
    {
      v9 = v11[2 * a3 + 1];
      if ( (unsigned int)v11[2 * a3] + (unsigned __int64)v9 > v10 )
      {
        result = -1073741735;
      }
      else if ( a5 < v9 )
      {
        result = -1073741789;
      }
      else
      {
        if ( a2 )
          result = ZwReadFile();
        else
          result = ZwWriteFile();
        if ( a6 )
          result = sub_7EB018(result);
      }
    }
  }
  return result;
}
