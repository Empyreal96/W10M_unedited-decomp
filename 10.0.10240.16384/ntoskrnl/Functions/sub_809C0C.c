// sub_809C0C 
 
// bad sp value at call has been detected, the output may be wrong!
int __fastcall sub_809C0C(int a1, int a2, unsigned int a3)
{
  _DWORD *v4; // r4
  unsigned int v5; // r7
  int v6; // r6
  unsigned __int64 v7; // r8
  unsigned int *v8; // r5
  int v9; // r3
  unsigned int v10; // r1
  int v11; // r3
  __int64 v12; // kr08_8
  int (__fastcall *v13)(int); // [sp-4h] [bp-4h]

  v6 = v4[3];
  if ( (v6 & 0x2000) != 0 )
    v7 = (unsigned __int64)a3 << 10;
  else
    v7 = (unsigned __int64)a3 << 20;
  if ( v5 * (unsigned __int64)(unsigned int)v4[32] < v7 )
    goto LABEL_17;
  if ( (v6 & 2) != 0 )
  {
    v4[32] = 1;
    v4[36] = v5;
    v4[37] = a2;
    goto LABEL_17;
  }
  if ( (v6 & 8) != 0 )
  {
    v8 = v4 + 153;
    v9 = v4[153];
    __dmb(0xBu);
    if ( (v9 & 1) == 0 )
    {
      EtwpGenerateFileName(v4 + 27, v4 + 55, v4 + 29);
      __dmb(0xBu);
      do
        v10 = __ldrex(v8);
      while ( __strex(v10 | 1, v8) );
      __dmb(0xBu);
    }
LABEL_17:
    JUMPOUT(0x75EB60);
  }
  v11 = v4[152];
  if ( (v11 & 0x100) == 0 )
  {
    v4[152] = v11 | 0x100;
    v12 = *(_QWORD *)&EtwpEventTracingProvRegHandle;
    if ( EtwEventEnabled(EtwpEventTracingProvRegHandle, dword_61ADA4, (int)ETW_EVENT_MAX_FILE_SIZE_REACHED) )
      EtwpEventWriteTemplateMaxFileSize(v12, HIDWORD(v12));
  }
  ++v4[45];
  return v13(-1073741432);
}
