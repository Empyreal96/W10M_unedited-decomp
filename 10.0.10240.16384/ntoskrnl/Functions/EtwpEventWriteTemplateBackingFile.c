// EtwpEventWriteTemplateBackingFile 
 
int EtwpEventWriteTemplateBackingFile(int a1, int a2, int a3, int a4, unsigned __int16 *a5, int a6, ...)
{
  int v7[21]; // [sp+8h] [bp-68h] BYREF
  va_list va; // [sp+78h] [bp+8h] BYREF

  va_start(va, a6);
  v7[0] = -1073741432;
  v7[2] = *((_DWORD *)a5 + 1);
  v7[3] = 0;
  v7[4] = *a5;
  v7[5] = 0;
  v7[6] = (int)&EtwpNull;
  v7[7] = 0;
  v7[8] = 2;
  v7[9] = 0;
  v7[10] = (int)v7;
  v7[11] = 0;
  v7[12] = 4;
  v7[13] = 0;
  va_copy((va_list)&v7[14], va);
  v7[15] = 0;
  v7[16] = 4;
  v7[17] = 0;
  return EtwWrite(a1, a2, (int)ETW_EVENT_BACKING_FILE_FULL, 0);
}
