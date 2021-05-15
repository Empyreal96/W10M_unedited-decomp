// ViCopyDeviceDescription 
 
int __fastcall ViCopyDeviceDescription(int result, const void **a2)
{
  int v3; // r6

  v3 = result;
  if ( (unsigned int)*a2 > 3 )
  {
    ViHalPreprocessOptions(&dword_618734, "Unknown version %x for DEVICE_DESCRIPTION (%p)", 37, *a2);
    result = VfReportIssueWithOptions(230, 37, (int)*a2, (int)a2, 0, &dword_618734);
  }
  *(_BYTE *)(v3 + 4) = *((_BYTE *)a2 + 4);
  *(_BYTE *)(v3 + 5) = *((_BYTE *)a2 + 5);
  *(_BYTE *)(v3 + 6) = *((_BYTE *)a2 + 6);
  *(_BYTE *)(v3 + 7) = *((_BYTE *)a2 + 7);
  *(_BYTE *)(v3 + 8) = *((_BYTE *)a2 + 8);
  *(_BYTE *)(v3 + 9) = *((_BYTE *)a2 + 9);
  *(_BYTE *)(v3 + 10) = *((_BYTE *)a2 + 10);
  *(_BYTE *)(v3 + 11) = *((_BYTE *)a2 + 11);
  *(_DWORD *)(v3 + 12) = a2[3];
  *(_DWORD *)(v3 + 16) = a2[4];
  *(_DWORD *)(v3 + 20) = a2[5];
  *(_DWORD *)(v3 + 24) = a2[6];
  *(_DWORD *)(v3 + 28) = a2[7];
  *(_DWORD *)(v3 + 32) = a2[8];
  *(_DWORD *)(v3 + 36) = a2[9];
  *(_DWORD *)v3 = *a2;
  if ( *a2 == (const void *)3 )
  {
    *(_DWORD *)(v3 + 40) = a2[10];
    *(_DWORD *)(v3 + 44) = a2[11];
    *(_DWORD *)(v3 + 48) = a2[12];
    *(_DWORD *)(v3 + 56) = a2[14];
    *(_DWORD *)(v3 + 60) = a2[15];
  }
  return result;
}
