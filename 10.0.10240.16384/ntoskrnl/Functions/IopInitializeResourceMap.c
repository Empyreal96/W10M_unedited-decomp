// IopInitializeResourceMap 
 
int IopInitializeResourceMap()
{
  char v1[16]; // [sp+1Ch] [bp-68h] BYREF
  char v2[8]; // [sp+2Ch] [bp-58h] BYREF
  char v3[8]; // [sp+34h] [bp-50h] BYREF

  RtlInitUnicodeString((unsigned int)v3, L"System Resources");
  RtlInitUnicodeString((unsigned int)v1, (unsigned __int16 *)&IopWstrPhysicalMemory);
  RtlInitUnicodeString((unsigned int)v2, L".Translated");
  return sub_969660();
}
