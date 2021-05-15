// DbgkpSectionToFileHandle 
 
int __fastcall DbgkpSectionToFileHandle(int a1)
{
  int result; // r0
  unsigned int v2; // r5
  int v3; // r4
  int v4[12]; // [sp+8h] [bp-30h] BYREF

  if ( MmGetFileNameForSection(a1, v4) < 0 )
    goto LABEL_2;
  v4[4] = 24;
  v4[5] = 0;
  v4[7] = 1600;
  v4[8] = 0;
  v4[9] = 0;
  v2 = v4[0];
  v4[6] = v4[0];
  v3 = ZwOpenFile();
  ExFreePoolWithTag(v2);
  if ( v3 < 0 )
LABEL_2:
    result = 0;
  else
    result = v4[1];
  return result;
}
