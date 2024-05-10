/*
 * Copyright (c) 2024, Andrew Kaster <akaster@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWeb/Bindings/PlatformObject.h>

namespace Web::CSS {

struct FontFaceDescriptors {
    String style = "normal"_string;
    String weight = "normal"_string;
    String stretch = "normal"_string;
    String unicode_range = "U+0-10FFFF"_string;
    String feature_settings = "normal"_string;
    String variation_settings = "normal"_string;
    String display = "auto"_string;
    String ascent_override = "normal"_string;
    String descent_override = "normal"_string;
    String line_gap_override = "normal"_string;
};

class FontFace final : public Bindings::PlatformObject {
    WEB_PLATFORM_OBJECT(FontFace, Bindings::PlatformObject);
    JS_DECLARE_ALLOCATOR(FontFace);

public:
    using FontFaceSource = Variant<String, JS::Handle<JS::ArrayBuffer>, JS::Handle<WebIDL::ArrayBufferView>>;

    [[nodiscard]] static JS::NonnullGCPtr<FontFace> construct_impl(JS::Realm&, String family, FontFaceSource source, FontFaceDescriptors const& descriptors);
    virtual ~FontFace() override = default;

    String family() const { return m_family; }
    WebIDL::ExceptionOr<void> set_family(String const&);

    String style() const { return m_style; }
    WebIDL::ExceptionOr<void> set_style(String const&);

    String weight() const { return m_weight; }
    WebIDL::ExceptionOr<void> set_weight(String const&);

    String stretch() const { return m_stretch; }
    WebIDL::ExceptionOr<void> set_stretch(String const&);

    String unicode_range() const { return m_unicode_range; }
    WebIDL::ExceptionOr<void> set_unicode_range(String const&);

    String feature_settings() const { return m_feature_settings; }
    WebIDL::ExceptionOr<void> set_feature_settings(String const&);

    String variation_settings() const { return m_variation_settings; }
    WebIDL::ExceptionOr<void> set_variation_settings(String const&);

    String display() const { return m_display; }
    WebIDL::ExceptionOr<void> set_display(String const&);

    String ascent_override() const { return m_ascent_override; }
    WebIDL::ExceptionOr<void> set_ascent_override(String const&);

    String descent_override() const { return m_descent_override; }
    WebIDL::ExceptionOr<void> set_descent_override(String const&);

    String line_gap_override() const { return m_line_gap_override; }
    WebIDL::ExceptionOr<void> set_line_gap_override(String const&);

    JS::ThrowCompletionOr<JS::NonnullGCPtr<JS::Promise>> load();

private:
    FontFace(JS::Realm&, String family, FontFaceSource source, FontFaceDescriptors const& descriptors);

    virtual void initialize(JS::Realm&) override;

    // FIXME: Should we be storing StyleValues instead?
    String m_family;
    String m_style;
    String m_weight;
    String m_stretch;
    String m_unicode_range;
    String m_feature_settings;
    String m_variation_settings;
    String m_display;
    String m_ascent_override;
    String m_descent_override;
    String m_line_gap_override;

    // https://drafts.csswg.org/css-font-loading/#css-connected
    bool m_is_css_connected { false };
};

}
