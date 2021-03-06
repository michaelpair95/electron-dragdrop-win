#pragma once
class OleDataObject : public IDataObject
{
private:
	LONG	   m_lRefCount = 0;
	FORMATETC *m_pFormatEtc = nullptr;
	STGMEDIUM *m_pStgMedium = nullptr;
	LONG	   m_nNumFormats = 0;

	int LookupFormatEtc(FORMATETC *pFormatEtc);
	HGLOBAL DupMem(HGLOBAL hMem);

public:
	OleDataObject(FORMATETC *fmtetc, STGMEDIUM *stgmed, int count);
	~OleDataObject();

	// IUnknown methods
	STDMETHOD(QueryInterface)(REFIID iid, LPVOID* ppvObject);
	STDMETHOD_(ULONG, AddRef)();
	STDMETHOD_(ULONG, Release)();

	// IDataObject methods
	STDMETHOD(GetData)(LPFORMATETC pFormatEtc, LPSTGMEDIUM pMedium);
	STDMETHOD(GetDataHere)(LPFORMATETC pFormatEtc, LPSTGMEDIUM pMedium);
	STDMETHOD(QueryGetData)(LPFORMATETC pFormatEtc);
	STDMETHOD(GetCanonicalFormatEtc)(LPFORMATETC pFormatEct, LPFORMATETC pFormatEtcOut);
	STDMETHOD(SetData)(LPFORMATETC pFormatEtc, LPSTGMEDIUM pMedium, BOOL fRelease);
	STDMETHOD(EnumFormatEtc)(DWORD dwDirection, LPENUMFORMATETC* ppEnumFormatEtc);
	STDMETHOD(DAdvise)(LPFORMATETC pFormatEtc, DWORD advf, LPADVISESINK pAdvSink, LPDWORD pdwConnection);
	STDMETHOD(DUnadvise)(DWORD dwConnection);
	STDMETHOD(EnumDAdvise)(LPENUMSTATDATA* ppEnumAdvise);

	static HRESULT Create(LPFORMATETC pFmtetc, LPSTGMEDIUM pStgmeds, UINT count, LPDATAOBJECT* ppDataObject);
};

