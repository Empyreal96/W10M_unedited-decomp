// McGenControlCallbackV2 
 
void __fastcall McGenControlCallbackV2(int a1, int a2, char a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  unsigned int v10; // r5
  __int64 v11; // kr08_8
  int v12; // r1
  unsigned int v13; // r0
  int v14; // r3
  int *i; // r5

  if ( a10 )
  {
    if ( a2 )
    {
      if ( a2 == 1 )
      {
        v10 = 0;
        *(_DWORD *)(a10 + 16) = a5;
        *(_BYTE *)(a10 + 40) = a3;
        *(_DWORD *)(a10 + 36) = 1;
        *(_DWORD *)(a10 + 20) = a6;
        *(_DWORD *)(a10 + 24) = a7;
        for ( *(_DWORD *)(a10 + 28) = a8; v10 < *(unsigned __int16 *)(a10 + 42); ++v10 )
        {
          v11 = *(_QWORD *)(*(_DWORD *)(a10 + 48) + 8 * v10);
          if ( *(unsigned __int8 *)(*(_DWORD *)(a10 + 52) + v10) <= (unsigned int)*(unsigned __int8 *)(a10 + 40)
            || !*(_BYTE *)(a10 + 40) )
          {
            if ( !v11 )
            {
              v12 = *(_DWORD *)(a10 + 44);
              v13 = v10 >> 5;
              v14 = *(_DWORD *)(v12 + 4 * (v10 >> 5)) | (1 << (v10 & 0x1F));
              goto LABEL_10;
            }
            if ( (*(_QWORD *)(a10 + 16) & v11) != 0 )
            {
              sub_554604();
              return;
            }
          }
          v12 = *(_DWORD *)(a10 + 44);
          v13 = v10 >> 5;
          v14 = *(_DWORD *)(v12 + 4 * (v10 >> 5)) & ~(1 << (v10 & 0x1F));
LABEL_10:
          *(_DWORD *)(v12 + 4 * v13) = v14;
        }
        ExAcquireResourceSharedLite((int)&algn_631E04[4], 1);
        for ( i = (int *)FsRtlTieringHeatData; i != &FsRtlTieringHeatData; i = (int *)*i )
        {
          if ( (Microsoft_Windows_Storage_Tiering_IoHeatEnableBits & 1) != 0 )
            Template_jq(Microsoft_Windows_Storage_Tiering_IoHeatHandle, MEMORY[0x64B094]);
        }
        ExpReleaseResourceForThreadLite((int)&algn_631E04[4], __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
      }
    }
    else
    {
      *(_DWORD *)(a10 + 36) = 0;
      *(_BYTE *)(a10 + 40) = 0;
      *(_DWORD *)(a10 + 16) = 0;
      *(_DWORD *)(a10 + 20) = 0;
      *(_DWORD *)(a10 + 24) = 0;
      *(_DWORD *)(a10 + 28) = 0;
      if ( *(_WORD *)(a10 + 42) )
        memset(*(_BYTE **)(a10 + 44), 0, 4 * ((*(unsigned __int16 *)(a10 + 42) - 1) / 32 + 1));
    }
  }
}
