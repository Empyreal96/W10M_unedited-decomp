// IopErrorLogThread 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IopErrorLogThread(int a1, int a2, int a3)
{
  int result; // r0
  unsigned int v4; // r5
  int v5; // r10
  int v6; // r4 OVERLAPPED
  unsigned int v7; // r8
  unsigned __int16 *v8; // r1
  _WORD *i; // r2
  unsigned __int16 v10; // r3
  char *v11; // r7
  int v12; // r9
  int v13; // r2
  int v14; // r0
  int v15; // r0
  int v16; // r3
  int v17; // r6
  int v18; // r2
  int v19; // r6
  __int16 v20; // r3
  int v21; // r2
  unsigned int v22; // r4
  int v23; // r0
  int v24[2]; // [sp+18h] [bp-658h] BYREF
  __int64 v25; // [sp+20h] [bp-650h] BYREF
  int v26; // [sp+28h] [bp-648h]
  unsigned int v27; // [sp+2Ch] [bp-644h]
  __int64 v28; // [sp+30h] [bp-640h] BYREF
  int v29; // [sp+38h] [bp-638h]
  __int64 v30; // [sp+40h] [bp-630h] BYREF
  __int16 v31[256]; // [sp+148h] [bp-528h] BYREF
  __int16 v32[256]; // [sp+348h] [bp-328h] BYREF
  char v33; // [sp+548h] [bp-128h] BYREF

  v26 = 0;
  v27 = 0;
  result = IopErrorLogConnectSession(a1, a2, a3, 0);
  if ( result )
  {
    v24[0] = 0;
    for ( result = IopErrorLogGetEntry(); result; result = IopErrorLogGetEntry() )
    {
      v4 = result - 4;
      v5 = *(_DWORD *)(result + 12);
      v29 = *(unsigned __int16 *)(result - 2);
      if ( v5 )
      {
        RtlInitUnicodeString((unsigned int)&v25, 0);
        if ( *(_DWORD *)(v5 + 32) )
        {
          *(_QWORD *)(&v6 - 1) = *(_QWORD *)(v5 + 28);
          v25 = *(_QWORD *)(&v6 - 1);
        }
        else
        {
          v6 = HIDWORD(v25);
        }
        v7 = (unsigned __int16)v25;
        if ( (_WORD)v25 )
        {
LABEL_15:
          for ( i = (_WORD *)(v6 + 2 * (v7 >> 1) - 2); *i != 92 && i != (_WORD *)v6; --i )
            ;
          if ( *i == 92 )
            ++i;
          v10 = v7 - (_WORD)i + v6;
          v7 = v10;
          LOWORD(v25) = v10;
          v6 = (int)i;
          HIDWORD(v25) = i;
          goto LABEL_22;
        }
        v24[0] = 0;
        if ( ObQueryNameStringMode(v5, (int)&v30, 264, v24, 0) >= 0 && v24[0] )
        {
          v6 = HIDWORD(v30);
          v25 = v30;
          goto LABEL_14;
        }
        v8 = (unsigned __int16 *)&dword_8CE900;
      }
      else
      {
        v8 = L"Application Popup";
      }
      RtlInitUnicodeString((unsigned int)&v25, v8);
      v6 = HIDWORD(v25);
LABEL_14:
      v7 = (unsigned __int16)v25;
      if ( (_WORD)v25 )
        goto LABEL_15;
LABEL_22:
      v24[0] = 0;
      v11 = &v33;
      v12 = 0;
      v13 = 264;
      if ( !*(_DWORD *)(v4 + 12) )
        goto LABEL_36;
      while ( 1 )
      {
        v14 = ObQueryNameStringMode(*(_DWORD *)(v4 + 12), (int)v11, v13, v24, 0);
        if ( v14 != -1073741820 )
          break;
        if ( v12 )
          goto LABEL_36;
        if ( ViVerifierDriverAddedThunkListHead )
        {
          v16 = (MmVerifierData & 0x10) != 0 ? 40 : 32;
          v15 = ExAllocatePoolWithTagPriority(1, v24[0], 538996553, v16);
        }
        else
        {
          v15 = ExAllocatePoolWithTag(1, v24[0], 538996553);
        }
        v11 = (char *)v15;
        if ( !v15 )
          goto LABEL_36;
        v13 = v24[0];
        v12 = 1;
      }
      if ( v14 >= 0 && v24[0] )
      {
        v17 = *((_DWORD *)v11 + 1);
        v28 = *(_QWORD *)v11;
      }
      else
      {
LABEL_36:
        RtlInitUnicodeString((unsigned int)&v28, (unsigned __int16 *)&dword_8CE900);
        v17 = HIDWORD(v28);
      }
      v31[0] = 0;
      v32[0] = 0;
      if ( v6 )
        RtlStringCchCopyNW(v31, 0x100u, v6, v7 >> 1);
      if ( v17 )
        RtlStringCchCopyNW(v32, 0x100u, v17, (unsigned __int16)v28 >> 1);
      if ( v12 == 1 )
        ExFreePoolWithTag((unsigned int)v11);
      v18 = *(_DWORD *)(v4 + 44);
      if ( (v18 == 1074004005 || v18 == 1074004004) && !wcsicmp((int)v31, L"NTFS") )
      {
        v27 = v4 + 112;
        v19 = (unsigned __int16)*(_DWORD *)(v4 + 76);
        v20 = *(_WORD *)(v4 + 34);
        v26 = v19;
        *(_WORD *)(v4 + 34) = v20 - v19;
      }
      else
      {
        v19 = v26;
      }
      if ( EtwWriteErrorLogEntry(IopErrorLogSession, unk_64B0DC, v4 + 32, v29 - 32, v4 + 24, v31, v32, v19, v27) < 0 )
      {
        IopErrorLogRequeueEntry((_QWORD *)(v4 + 4));
        return IopErrorLogQueueRequest();
      }
      __dmb(0xBu);
      v21 = -*(unsigned __int16 *)(v4 + 2);
      do
        v22 = __ldrex(&IopErrorLogAllocation);
      while ( __strex(v22 + v21, &IopErrorLogAllocation) );
      __dmb(0xBu);
      v23 = *(_DWORD *)(v4 + 12);
      if ( v23 )
        ObfDereferenceObject(v23);
      if ( v5 )
        ObfDereferenceObject(*(_DWORD *)(v4 + 16));
      ExFreePoolWithTag(v4);
      v24[0] = 0;
    }
  }
  return result;
}
