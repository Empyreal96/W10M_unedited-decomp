// DbgkpLkmdSqmIncrementDword 
 
int DbgkpLkmdSqmIncrementDword(int a1, int a2, ...)
{
  int v3; // [sp+8h] [bp-58h] BYREF
  int var54[22]; // [sp+Ch] [bp-54h] BYREF
  va_list varg_r2; // [sp+70h] [bp+10h] BYREF

  va_start(varg_r2, a2);
  v3 = 1;
  var54[0] = 6;
  var54[1] = (int)var54;
  var54[2] = 0;
  var54[3] = 4;
  var54[4] = 0;
  var54[5] = (int)dword_416908;
  var54[6] = 0;
  var54[7] = 16;
  var54[8] = 0;
  va_copy((va_list)&var54[9], varg_r2);
  var54[10] = 0;
  var54[11] = 4;
  var54[12] = 0;
  var54[13] = (int)&v3;
  var54[14] = 0;
  var54[15] = 4;
  var54[16] = 0;
  return EtwWrite(a1, a2, (int)&SQM_INCREMENT_DWORD, 0);
}
