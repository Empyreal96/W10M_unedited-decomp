// EtwpEventWriteTemplateMaxFileSize 
 
int EtwpEventWriteTemplateMaxFileSize(int a1, int a2, int a3, int a4, unsigned __int16 *a5, unsigned __int16 *a6, int a7, ...)
{
  int v7; // r3
  int v8; // r3
  int var88[35]; // [sp+8h] [bp-88h] BYREF
  int v11; // [sp+B4h] [bp+24h] BYREF
  va_list va; // [sp+B4h] [bp+24h]
  va_list va1; // [sp+B8h] [bp+28h] BYREF

  va_start(va1, a7);
  va_start(va, a7);
  v11 = va_arg(va1, _DWORD);
  var88[0] = -1073741432;
  v7 = *((_DWORD *)a5 + 1);
  var88[6] = (int)&EtwpNull;
  var88[7] = 0;
  var88[2] = v7;
  var88[3] = 0;
  v8 = *a5;
  var88[14] = (int)&EtwpNull;
  var88[15] = 0;
  var88[4] = v8;
  var88[5] = 0;
  var88[8] = 2;
  var88[9] = 0;
  var88[10] = *((_DWORD *)a6 + 1);
  var88[11] = 0;
  var88[12] = *a6;
  var88[13] = 0;
  var88[16] = 2;
  var88[17] = 0;
  var88[18] = (int)var88;
  var88[19] = 0;
  var88[20] = 4;
  var88[21] = 0;
  va_copy((va_list)&var88[22], va);
  var88[23] = 0;
  var88[24] = 4;
  var88[25] = 0;
  va_copy((va_list)&var88[26], va1);
  var88[27] = 0;
  var88[28] = 8;
  var88[29] = 0;
  return EtwWrite(a1, a2, (int)ETW_EVENT_MAX_FILE_SIZE_REACHED, 0);
}
