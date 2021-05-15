// SepAdtGenerateDiscardAudit 
 
unsigned int __fastcall SepAdtGenerateDiscardAudit(unsigned int a1)
{
  int v2; // r3
  unsigned int result; // r0
  int v4[170]; // [sp+0h] [bp-2A8h] BYREF

  memset(v4, 0, 664);
  v4[0] = 1;
  v4[4] = 524390;
  v4[1] = 4612;
  v4[6] = 4;
  v2 = *(unsigned __int8 *)(SeLocalSystemSid + 1);
  v4[10] = SeLocalSystemSid;
  v4[7] = 4 * (v2 + 2);
  v4[11] = 1;
  v4[12] = 24;
  v4[15] = (int)&SeSubsystemName;
  v4[16] = 27;
  v4[17] = 4;
  v4[18] = *(_DWORD *)(a1 + 16);
  v4[2] = 3;
  result = SepAdtLogAuditRecord((int)v4);
  if ( *(_BYTE *)(a1 + 20) )
    result = ExFreePoolWithTag(a1);
  return result;
}
