// VfCheckImageCompliance 
 
int *__fastcall VfCheckImageCompliance(int *result)
{
  int *v1; // r7
  int *v2; // r4
  unsigned int v3; // r8
  int *v4; // r5
  unsigned int v5; // r1
  int v6; // r2
  int v7; // r3
  unsigned int v8; // r1
  int v9; // [sp+8h] [bp-30h] BYREF
  int v10; // [sp+Ch] [bp-2Ch]
  char v11; // [sp+10h] [bp-28h]

  v1 = result;
  if ( (MmVerifierData & 0x2000000) != 0 )
  {
    result = (int *)RtlImageNtHeader(result[6]);
    v2 = result;
    if ( result )
    {
      v3 = 0;
      v4 = (int *)((char *)result + *((unsigned __int16 *)result + 10) + 24);
      if ( *((_WORD *)result + 3) )
      {
        do
        {
          if ( (v4[9] & 0xA0000000) == -1610612736 )
          {
            v9 = *v4;
            v10 = v4[1];
            v11 = 0;
            if ( stricmp((unsigned __int8 *)&v9, "INIT") || (VfOptionFlags & 0x100) != 0 )
            {
              ViCiPreprocessOptions(
                &dword_618710,
                "The image %wZ contains an executable and writable section 0x%p (name %s).",
                8195,
                v1 + 11,
                v4,
                &v9);
              VfReportIssueWithOptions(196, 8195, (int)(v1 + 11), (int)v4, (int)&v9, &dword_618710);
            }
            if ( (MmVerifierData & 0x1000) != 0 )
              ViTargetIncrementCounter(v1[7]);
            do
              v5 = __ldrex(dword_620E04);
            while ( __strex(v5 + 1, dword_620E04) );
          }
          v6 = *((unsigned __int16 *)v2 + 12);
          if ( v6 == 267 || v6 == 523 )
            v7 = v2[14];
          else
            v7 = 4096;
          if ( !v7 || (v7 & 0xFFF) != 0 )
          {
            v9 = *v4;
            v10 = v4[1];
            v11 = 0;
            ViCiPreprocessOptions(
              &dword_618708,
              "The image %wZ contains section 0x%p that is not page aligned (name %s).",
              8196,
              v1 + 11,
              v4,
              &v9);
            VfReportIssueWithOptions(196, 8196, (int)(v1 + 11), (int)v4, (int)&v9, &dword_618708);
            if ( (MmVerifierData & 0x1000) != 0 )
              ViTargetIncrementCounter(v1[7]);
            do
              v8 = __ldrex(&dword_620E04[1]);
            while ( __strex(v8 + 1, &dword_620E04[1]) );
          }
          ++v3;
          result = &dword_618708;
          v4 += 10;
        }
        while ( v3 < *((unsigned __int16 *)v2 + 3) );
      }
    }
  }
  return result;
}
