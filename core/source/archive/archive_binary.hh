// Copyright © 2021 Luis Michaelis
// Licensed under MIT (https://mit-license.org/).
#pragma once
#include <phoenix/archive.hh>

namespace phoenix {
	class archive_reader_binary final : public archive_reader {
	public:
		inline archive_reader_binary(reader& in, archive_header&& header) : archive_reader(in, std::move(header)) {}

		bool read_object_begin(archive_object& obj) override;
		bool read_object_end() override;
		std::string read_string() override;
		s32 read_int() override;
		float read_float() override;
		u8 read_byte() override;
		u16 read_word() override;
		u32 read_enum() override;
		bool read_bool() override;
		color read_color() override;
		glm::vec3 read_vec3() override;
		glm::vec2 read_vec2() override;
		std::tuple<glm::vec3, glm::vec3> read_bbox() override;
		glm::mat3x3 read_mat3x3() override;
		std::vector<u8> read_raw_bytes() override;

	protected:
		void skip_entry() override;

	public:
		void skip_object(bool skip_current) override;

	protected:
		void read_header() override;

	private:
		int _m_objects {0};
	};
} // namespace phoenix
